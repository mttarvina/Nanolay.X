/* ************************************************************************** */
// Nanolay - SCCP Library Header File
//
// Description:     Custom dsPIC33CK library for SCCP functions. Should be
//                  included in the nanolay.h file
//
// Target Device:   dsPIC33CKxxxMP202  
//
// Author:          Mark Angelo Tarvina (mttarvina)
// Email:           mttarvina@gmail.com
// Revision:        1.0
// Last Updated:    25.Feb.2023
/* ************************************************************************** */

#ifndef _NANOLAY_SCCP_H
#define	_NANOLAY_SCCP_H


#include "nanolay.h"
 

// 1us clock count @ FOSC/2 clock
#define SCCP_1US_COUNT_8MHZ     0x04
#define SCCP_1US_COUNT_20MHZ    0x0A
#define SCCP_1US_COUNT_50MHZ    0x19
#define SCCP_1US_COUNT_100MHZ   0x32

// 1ms clock count @ FOSC/2 clock
#define SCCP_1MS_COUNT_8MHZ     3999
#define SCCP_1MS_COUNT_20MHZ    9999
#define SCCP_1MS_COUNT_50MHZ    24999
#define SCCP_1MS_COUNT_100MHZ   49999


#define SCCP_PWM_MIN_PERIOD     40                                              // Maximum frequency of 25kHz


typedef struct tmr2_obj {
    uint_fast16_t           intA_countmax;
    uint_fast16_t           intB_countmax;
    volatile uint_fast16_t  intA_counter;
    volatile uint_fast16_t  intB_counter; 
} TMR2_OBJ;


typedef struct pwm_obj {
    uint_fast16_t           pin;
    uint_fast16_t           period;
    uint_fast16_t           maxPeriod;
    uint_fast16_t           minPeriod;
    float                   duty;
} PWM_OBJ;


// *****************************************************************************
// *****************************************************************************
// Timer2 [SCCP1] is a dual 16bit general purpose timer interrupt. Custom ISRs
//      can be individually assigned to TMR2_InterruptHandlerA and
//      TMR2_InterruptHandlerB                  
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// @desc:       Initialize SCCP1
// @args:       activeOnIdle [bool]
//              activeOnSleep [bool]
// @returns:    None
// *****************************************************************************
void TMR2_Init(bool activeOnIdle, bool activeOnSleep);


// *****************************************************************************
// @desc:       Assigns a user defined function as interrupt callback routine,
//                  then set the callback interrupt interval.
// @args:       interval_ms [uint_fast16_t]: interval in ms
//              InterruptHandler [pointer]: User defined ISR
//              priority [uint_fast8_t]: priority level from 1-7
// @returns:    None
// *****************************************************************************
void TMR2_SetInterruptA(uint_fast16_t interval_ms, void (* InterruptHandler)(void), uint_fast8_t priority);


// *****************************************************************************
// @desc:       Change interrupt interval for interrupt A
// @args:       interval_ms [uint_fast16_t]: interval in ms
// @returns:    None
// *****************************************************************************
void TMR2_SetInterruptIntervalA(uint_fast16_t interval_ms);


// *****************************************************************************
// @desc:       Assigns a user defined function as interrupt callback routine,
//                  then set the callback interrupt interval.
// @args:       interval_ms [uint_fast16_t]: interval in ms
//              InterruptHandler [pointer]: User defined ISR
//              priority [uint_fast8_t]: priority level from 1-7
// @returns:    None
// *****************************************************************************
void TMR2_SetInterruptB(uint_fast16_t interval_ms, void (* InterruptHandler)(void), uint_fast8_t priority);


// *****************************************************************************
// @desc:       Change interrupt interval for interrupt B
// @args:       interval_ms [uint_fast16_t]: interval in ms
// @returns:    None
// *****************************************************************************
void TMR2_SetInterruptIntervalB(uint_fast16_t interval_ms);


// *****************************************************************************
// @desc:       Start SCCP1 timer, enable interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void TMR2_Start(void);


// *****************************************************************************
// @desc:       Enable interrupt for interrupt handler A
// @args:       None
// @returns:    None
// *****************************************************************************
void TMR2_EnableInterruptA(void);


// *****************************************************************************
// @desc:       Disable interrupt for interrupt handler A
// @args:       None
// @returns:    None
// *****************************************************************************
void TMR2_DisableInterruptA(void);


// *****************************************************************************
// @desc:       Enable interrupt for interrupt handler B
// @args:       None
// @returns:    None
// *****************************************************************************
void TMR2_EnableInterruptB(void);


// *****************************************************************************
// @desc:       Disable interrupt for interrupt handler B
// @args:       None
// @returns:    None
// *****************************************************************************
void TMR2_DisableInterruptB(void);


// *****************************************************************************
// @desc:       Stop SCCP1 timer, disable all interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void TMR2_Stop(void);




// *****************************************************************************
// *****************************************************************************
// Timer3 [SCCP2] is a single 32bit general purpose timer interrupt. Custom ISR
//      can be assigned to TMR3_InterruptHandler
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// @desc:       Initialize SCCP2
// @args:       activeOnIdle [bool]
//              activeOnSleep [bool]
// @returns:    None
// *****************************************************************************
void TMR3_Init(bool activeOnIdle, bool activeOnSleep);


// *****************************************************************************
// @desc:       Assigns a user defined function as interrupt callback routine,
//                  then set the callback interrupt interval.
// @args:       interval_us [uint_fast32_t]: interval in us, recommended minimum
//                  value is 20us
//              InterruptHandler [pointer]: User defined ISR
//              priority [uint_fast8_t]: priority level from 1-7
// @returns:    None
// *****************************************************************************
void TMR3_SetInterrupt(uint_fast32_t interval_us, void (* InterruptHandler)(void), uint_fast8_t priority);


// *****************************************************************************
// @desc:       Start SCCP2 timer, enable interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void TMR3_Start(void);


// *****************************************************************************
// @desc:       Stop SCCP2 timer, disable all interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void TMR3_Stop(void);




// *****************************************************************************
// *****************************************************************************
// Timer4 [SCCP3] is a single 32bit general purpose timer interrupt. Custom ISR
//      can be assigned to TMR4_InterruptHandler
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// @desc:       Initialize SCCP3
// @args:       activeOnIdle [bool]
//              activeOnSleep [bool]
// @returns:    None
// *****************************************************************************
void TMR4_Init(bool activeOnIdle, bool activeOnSleep);


// *****************************************************************************
// @desc:       Assigns a user defined function as interrupt callback routine,
//                  then set the callback interrupt interval.
// @args:       interval_us [uint_fast32_t]: interval in us, recommended minimum
//                  value is 20us
//              InterruptHandler [pointer]: User defined ISR
//              priority [uint_fast8_t]: priority level from 1-7
// @returns:    None
// *****************************************************************************
void TMR4_SetInterrupt(uint_fast32_t interval_us, void (* InterruptHandler)(void), uint_fast8_t priority);


// *****************************************************************************
// @desc:       Start SCCP3 timer, enable interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void TMR4_Start(void);


// *****************************************************************************
// @desc:       Stop SCCP3 timer, disable all interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void TMR4_Stop(void);




// *****************************************************************************
// *****************************************************************************
// PWMA [SCCP4] is a 16bit general purpose PWM generator. PWM can be assigned to
//      any GPIO pin of PORT_A
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// @desc:       Assign PWM waveform to a GPIO pin, setup period. Uses SCCP4
// @args:       pin [uint_fast16_t]: GPIO Pin of PORT_A
//              period_us [uint_fast16_t]: period in us
//              activeOnIdle [bool]
//              activeOnSleep [bool]
//              priority [uint_fast8_t]: interrupt priority from 1-7
// @returns:    None
// *****************************************************************************
void PWMA_Init(uint_fast16_t pin, uint_fast16_t period_us, bool activeOnIdle, bool activeOnSleep, uint_fast8_t priority);


// *****************************************************************************
// @desc:       Set the duty cycle from 0 - 100%
// @args:       duty [float]: 0 - 1.0
// @returns:    None
// *****************************************************************************
void PWMA_SetDuty(float duty);


// *****************************************************************************
// @desc:       Start SCCP4 module, enable all interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void PWMA_Start(void);


// *****************************************************************************
// @desc:       Stop SCCP4 module, disable all interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void PWMA_Stop(void);




// *****************************************************************************
// *****************************************************************************
// PWMB1 [SCCP5] is a 16bit general purpose PWM generator. PWM can be assigned to
//      any GPIO pin of PORT_B
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// @desc:       Assign PWM waveform to a GPIO pin, setup period. Uses SCCP5
// @args:       pin [uint_fast16_t]: GPIO Pin of PORT_B
//              period_us [uint_fast16_t]: period in us
//              activeOnIdle [bool]
//              activeOnSleep [bool]
//              priority [uint_fast8_t]: interrupt priority from 1-7
// @returns:    None
// *****************************************************************************
void PWMB1_Init(uint_fast16_t pin, uint_fast16_t period_us, bool activeOnIdle, bool activeOnSleep, uint_fast8_t priority);


// *****************************************************************************
// @desc:       Set the duty cycle from 0 - 100%
// @args:       duty [float]: 0 - 1.0
// @returns:    None
// *****************************************************************************
void PWMB1_SetDuty(float duty);


// *****************************************************************************
// @desc:       Start SCCP5 module, enable all interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void PWMB1_Start(void);


// *****************************************************************************
// @desc:       Stop SCCP5 module, disable all interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void PWMB1_Stop(void);




// *****************************************************************************
// *****************************************************************************
// PWMB2 [SCCP6] is a 16bit general purpose PWM generator. PWM can be assigned to
//      any GPIO pin of PORT_B
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// @desc:       Assign PWM waveform to a GPIO pin, setup period. Uses SCCP6
// @args:       pin [uint_fast16_t]: GPIO Pin of PORT_B
//              period_us [uint_fast16_t]: period in us
//              activeOnIdle [bool]
//              activeOnSleep [bool]
//              priority [uint_fast8_t]: interrupt priority from 1-7
// @returns:    None
// *****************************************************************************
void PWMB2_Init(uint_fast16_t pin, uint_fast16_t period_us, bool activeOnIdle, bool activeOnSleep, uint_fast8_t priority);


// *****************************************************************************
// @desc:       Set the duty cycle from 0 - 100%
// @args:       duty [float]: 0 - 1.0
// @returns:    None
// *****************************************************************************
void PWMB2_SetDuty(float duty);


// *****************************************************************************
// @desc:       Start SCCP6 module, enable all interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void PWMB2_Start(void);


// *****************************************************************************
// @desc:       Stop SCCP6 module, disable all interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void PWMB2_Stop(void);




// *****************************************************************************
// *****************************************************************************
// PWMB3 [SCCP7] is a 16bit general purpose PWM generator. PWM can be assigned to
//      any GPIO pin of PORT_B
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// @desc:       Assign PWM waveform to a GPIO pin, setup period. Uses SCCP6
// @args:       pin [uint_fast16_t]: GPIO Pin of PORT_B
//              period_us [uint_fast16_t]: period in us
//              activeOnIdle [bool]
//              activeOnSleep [bool]
//              priority [uint_fast8_t]: interrupt priority from 1-7
// @returns:    None
// *****************************************************************************
void PWMB3_Init(uint_fast16_t pin, uint_fast16_t period_us, bool activeOnIdle, bool activeOnSleep, uint_fast8_t priority);


// *****************************************************************************
// @desc:       Set the duty cycle from 0 - 100%
// @args:       duty [float]: 0 - 1.0
// @returns:    None
// *****************************************************************************
void PWMB3_SetDuty(float duty);


// *****************************************************************************
// @desc:       Start SCCP7 module, enable all interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void PWMB3_Start(void);


// *****************************************************************************
// @desc:       Stop SCCP7 module, disable all interrupts
// @args:       None
// @returns:    None
// *****************************************************************************
void PWMB3_Stop(void);


#endif // _NANOLAY_SCCP_H
