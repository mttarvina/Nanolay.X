/* ************************************************************************** */
// Nanolay - Main Library Header File
//
// Description:     Custom dsPIC33CK library to be used with Nanolay dev Board
//                  as well as any future projects that uses dcPIC33CKxxxMP202
//
// Target Device:   dsPIC33CKxxxMP202  
//
// Author:          Mark Angelo Tarvina (~tarvs)
// Email:           mttarvina@gmail.com
// Revision:        1.0
// Last Updated:    25.Feb.2023
/* ************************************************************************** */


#ifndef _NANOLAY_H
#define	_NANOLAY_H


#include <p33CK256MP202.h>
#include <stdbool.h>
#include <stdio.h>


#define CLKOUT_EN           false                                               // used in #pragma definitions for debug only, FOSC/2 at OSC2 pin
#define FOSC_4MHZ_EN        false                                               // used in #pragma definitions


typedef enum clock_freq {
    // FOSC_4MHZ,
    FOSC_8MHZ,
    FOSC_20MHZ,
    FOSC_50MHZ,
    FOSC_100MHZ
} Clock_Freq;


// *****************************************************************************
// @desc:       Initialize system CLK registers. This is called by Sys_Init()
// @args:       clk [ClockFreq]: Fosc Frequency
// @returns:    None
// *****************************************************************************
void Sys_ClockSet(Clock_Freq clk);


// *****************************************************************************
// @desc:       Returns a value corresponding to an element defined in ClockFreq
//                  enum 
// @args:       None
// @returns:    [ClockFreq]: Master_Clock
// *****************************************************************************
Clock_Freq Sys_GetMasterClkFreq(void);


// *****************************************************************************
// @desc:       Disables all peripherals. Called by Sys_Init(). Each peripheral
//                  will be enabled once the corresponding init function is
//                  called in the main program.
// @args:       None
// @returns:    None
// *****************************************************************************
void Sys_DisableAllPeripherals(void);


// *****************************************************************************
// @desc:       Initialize system clock, peripherals, and default GPIO states.
//                  Must be called at the start of main program
// @args:       clk [ClockFreq]: Fosc Frequency
// @returns:    None
// *****************************************************************************
void Sys_Init(Clock_Freq clk);


#include "nanolay_gpio.h"
#include "nanolay_tmr1.h"
#include "nanolay_sccp.h"
//#include "nanolay_adc.h"
#include "nanolay_dac.h"
//#include "nanolay_pwmx.h"

#endif // _NANOLAY_H