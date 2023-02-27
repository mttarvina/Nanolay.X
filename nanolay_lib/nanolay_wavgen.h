/* ************************************************************************** */
// Nanolay - Wave Generator Library Header File
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


#ifndef _NANOLAY_WAVGEN_H
#define	_NANOLAY_WAVGEN_H


#include "nanolay.h"


#define SAMPLE_SIZE     1600                                                    // 1600 samples in the lookup table
#define INT_PRIORITY    2


typedef struct sine_waveform {
    uint_fast16_t       frequency;
    uint_fast8_t        samplingInterval;
    uint_fast32_t       samplingFrequency;
    uint_fast16_t       index;
    uint_fast8_t        stepSize;
} WAV_Sine;


// *****************************************************************************
// @desc:       Initialize Sine wave generator. Output at pin at PA3/RA3/AN3.
//                  Works only at Fosc = 20MHz and above. Uses SCCP8 as timer.
// @args:       activeOnIdle [bool]: true = active on idle
//              activeOnSleep [bool]: true = active on sleep
//              freq [uint_fast16_t]: frequency in Hz (works up to 5kHz)
//              samplingFreq [uint_fast32_t]: sampling frequency in Hz
// @returns:    None
// *****************************************************************************
void WAV_Sine_Init(bool activeOnIdle, bool activeOnSleep, uint_fast16_t freq, uint_fast32_t samplingFreq);


// *****************************************************************************
// @desc:       Starts the sine wave generator output at pin RA3
// @args:       None
// @returns:    None
// *****************************************************************************
void WAV_Sine_Start(void);


// *****************************************************************************
// @desc:       Stops the sine wave generator output at pin RA3
// @args:       None
// @returns:    None
// *****************************************************************************
void WAV_Sine_Stop(void);


// *****************************************************************************
// @desc:       Sets the sine wave frequency
// @args:       freq [uint_fast16_t]: Frequency in Hz (works up to 5kHz)
// @returns:    None
// *****************************************************************************
void WAV_Sine_SetFrequency(uint_fast16_t freq);


// *****************************************************************************
// @desc:       Initializes the SCCP8 module and used as a 32bit timer with 1us
//                  resolution
// @args:       activeOnIdle [bool]: true = active on idle
//              activeOnSleep [bool]: true = active on sleep
//              interval_us [uint_fast32_t]: interval in us. Recommended minimum
//                  is 10us (100kHz sampling frequency)
//              priority [uint_fast8_t]: interrupt priority
// @returns:    None
// *****************************************************************************
void SCCP8_Init(bool activeOnIdle, bool activeOnSleep, uint_fast32_t interval_us, uint_fast8_t priority);

#endif	// NANOLAY_WAVGEN_H