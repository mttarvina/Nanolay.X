/* ************************************************************************** */
// Nanolay - Timer1 Library Header File
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

#ifndef _NANOLAY_TMR1_H
#define	_NANOLAY_TMR1_H


#include "nanolay.h"


// 16bit counter values for 1ms period
typedef enum tmr1_1ms_count {
    // TMR1_1MS_COUNT_4MHZ = 1999,
    TMR1_1MS_COUNT_8MHZ = 3999,
    TMR1_1MS_COUNT_20MHZ = 9999,
    TMR1_1MS_COUNT_50MHZ = 24999,
    TMR1_1MS_COUNT_100MHZ = 49999,
} TMR1_1MS_Count;


// builtin timer1 struct
typedef struct tmr1_obj {
    bool                        interruptEn;                                    // true if there's an existing User define ISR that will be triggered at an interval
    bool                        isWaiting;                                      // used in builtin wait() function
    uint_fast16_t               intCountmax;
    volatile uint_fast16_t      intCounter; 
    volatile uint_fast16_t      waitCounter;
    volatile unsigned long long millisCounter;
} TMR1_Obj;



// *****************************************************************************
// @desc:       Enable Timer1 peripheral, initialize registers. Enables millis()
//                  function by default.
// @args:       activeOnIdle [bool]: module is active when device is in idle
//                  mode
// @returns:    None
// *****************************************************************************
void TMR1_Init(bool activeOnIdle);


// *****************************************************************************
// @desc:       Assigns a user defined function as interrupt callback routine,
//                  sets the callback interval. Only works if Timer1 is enabled
//                  as Interrupt
// @args:       interval [uint_fast16_t]: Callback interval in ms
//              InterruptHandler [func pointer]: Address of user defined ISR
//              priority [uint_fast8_t]: priority level from 1-7
// @returns:    None
// *****************************************************************************
void TMR1_SetInterrupt(uint_fast16_t interval, void (* InterruptHandler)(void), uint_fast8_t priority);


// *****************************************************************************
// @desc:       Change Timer1 interrupt interval
// @args:       interval [uint_fast16_t]: New callback interval in ms
// @returns:    None
// *****************************************************************************
void TMR1_SetInterruptInterval(uint_fast16_t interval);


// *****************************************************************************
// @desc:       Start Timer1, enable interrupt, clear interrupt flag. Must be
//                  called after all necessary initializations for Timer1
// @args:       None
// @returns:    None
// *****************************************************************************
void TMR1_Start(void);


// *****************************************************************************
// @desc:       Stop Timer1, disable interrupt, reset all counters
// @args:       None
// @returns:    None
// *****************************************************************************
void TMR1_Stop(void);


// *****************************************************************************
// @desc:       Wait for a specified duration in ms. Uses Timer1. This is a
//                  blocking function
// @args:       duration_ms [uint_fast16_t]: duration in ms
// @returns:    None
// *****************************************************************************
void wait(uint_fast16_t duration_ms);


// *****************************************************************************
// @desc:       Returns the value of millisecond counter since Timer1 was
//                  started.
// @args:       None
// @returns:    [unsigned long long]: value of millisecond counter
// *****************************************************************************
unsigned long long millis(void);


#endif // _NANOLAY_TMR1_H