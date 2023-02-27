/* ************************************************************************** */
// Nanolay - DAC Library Header File
//
// Description:     Custom dsPIC33CK library for DAC functions. Should be
//                  included in the nanolay.h file
//
// Target Device:   dsPIC33CKxxxMP202  
//
// Author:          Mark Angelo Tarvina (mttarvina)
// Email:           mttarvina@gmail.com
// Revision:        1.0
// Last Updated:    13.Apr.21
/* ************************************************************************** */


#ifndef _NANOLAY_DAC_H
#define	_NANOLAY_DAC_H


#include "nanolay.h"


#define MIN_DAC_VAL     205
#define MAX_DAC_VAL     3890


typedef struct dac_stat {
    bool    dac1En;
    bool    dac2En;
    bool    dac3En;
} DAC_Stat;


// *****************************************************************************
// @desc:       Initialize DAC1 module. Enables DACOUT pin at PA3/RA3/AN3.
//                  Works only at Fosc = 20MHz and above
// @args:       activeOnIdle [bool]: true = continues operation in Idle mode
// @returns:    None
// *****************************************************************************
void DAC_Init(bool activeOnIdle);


// *****************************************************************************
// @desc:       Outputs a 12bit value from 0.05AVDD to 0.95AVDD to PA3/RA3/AN3
// @args:       val [uint_fast16_t]: 12bit DAC value
// @returns:    None
// *****************************************************************************
void DAC_Write(uint_fast16_t val);


#endif	// NANOLAY_DAC_H

