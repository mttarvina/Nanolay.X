/* ************************************************************************** */
// Nanolay - Timer1 Library Source File
//
// Description:     Custom dsPIC33CK library for Timer1 functions. Should be
//                  included in the nanolay.h file
//
// Target Device:   dsPIC33CKxxxMP202  
//
// Author:          Mark Angelo Tarvina (~tarvs)
// Email:           mttarvina@gmail.com
// Revision:        1.0
// Last Updated:    25.Feb.2023
/* ************************************************************************** */

#include "nanolay_tmr1.h"


static TMR1_Obj timer1;
void (*TMR1_InterruptHandler)(void) = NULL;


void TMR1_Init(bool activeOnIdle) {    
    Clock_Freq clk = Sys_GetMasterClkFreq();                                    // Get master clock frequency set by Sys_Init()
    PMD1bits.T1MD = 0;                                                          // enable TIMER1 peripheral
    TMR1 = 0x00;                                                                // Clear TMR1 register; 
    
    switch ( clk ) {
        // case FOSC_4MHZ:
        //     PR1 = TMR1_1MS_COUNT_4MHZ;
        //     break;
        case FOSC_8MHZ:
            PR1 = TMR1_1MS_COUNT_8MHZ;
            break;
        case FOSC_20MHZ:
            PR1 = TMR1_1MS_COUNT_20MHZ;
            break;
        case FOSC_50MHZ:
            PR1 = TMR1_1MS_COUNT_50MHZ;
            break;
        case FOSC_100MHZ:
            PR1 = TMR1_1MS_COUNT_100MHZ;
            break;
        default:
            break;
    }

    T1CON = 0x0000;
    T1CONbits.TSIDL = !activeOnIdle;
    timer1.interruptEn = false;
    timer1.isWaiting = false;
    T1CONbits.TON = false;                                                      // Disable Timer1
    IEC0bits.T1IE = false;                                                      // Disabled Timer1 interrupt
}


void TMR1_SetInterrupt(uint_fast16_t interval, void (* InterruptHandler)(void), uint_fast8_t priority){ 
    IPC0bits.T1IP = priority;
    TMR1_InterruptHandler = InterruptHandler;
    timer1.intCountmax = interval;
    timer1.interruptEn = true;
}


void TMR1_SetInterruptInterval(uint_fast16_t interval){
    timer1.intCountmax = interval;
}


void TMR1_Start(void) {
    timer1.intCounter = 0;
    timer1.waitCounter = 0;
    timer1.millisCounter = 0;
    IFS0bits.T1IF = false;                                                      // Reset Timer1 interrupt flag
    IEC0bits.T1IE = true;                                                       // Enable Timer1 interrupt
    T1CONbits.TON = true;                                                       // Enabled Timer1
}


void TMR1_Stop(void) {
    T1CONbits.TON = false;                                                      // Disable Timer1
    IEC0bits.T1IE = false;                                                      // Disabled Timer1 interrupt
    // timer1.intCounter = 0;                                                      // reset all timer1 counter
    // timer1.waitCounter = 0;                                                     // reset all timer1 counter
    // timer1.millisCounter = 0;                                                   // reset all timer1 counter
}


void wait(uint_fast16_t duration_ms){
    timer1.waitCounter = 0;
    timer1.isWaiting = true;
    while (timer1.waitCounter < duration_ms){
        // do nothing
    }
    timer1.isWaiting = false;
}


unsigned long long millis( void ){
    return timer1.millisCounter;
}


void __attribute__ ((interrupt, no_auto_psv)) _T1Interrupt() {
    IFS0bits.T1IF = false;
    
    timer1.millisCounter++;

    if ( timer1.interruptEn ){
        timer1.intCounter++;
        if (timer1.intCounter >= timer1.intCountmax){
            timer1.intCounter = 0;
            TMR1_InterruptHandler();
        }
    }

    if ( timer1.isWaiting ){
        timer1.waitCounter++;
    } 
}
