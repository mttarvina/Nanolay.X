/* ************************************************************************** */
// Nanolay - Main C File
//
// Author:          Mark Angelo Tarvina (mttarvina)
// Email:           mttarvina@gmail.com
// Revision:        1.0
// Last Updated:    25.Feb.2023
/* ************************************************************************** */

#include "nanolay_lib/nanolay.h"
#include "nanolay_lib/nanolay_wavgen.h"


int main(void) {    
    // SETUP
    Sys_Init(FOSC_20MHZ);
    GPIO_SetPortBPin(PIN0, OUTPUT, false, false, false);
    GPIO_SetPortBPin(PIN1, OUTPUT, false, false, false);
    GPIO_DrivePortBPin(PIN0, HIGH);
    GPIO_DrivePortBPin(PIN1, HIGH);

    WAV_Sine_Init(1000, 100000);                                                   // 1kHz @ 100kHz sampling frequency
    
    // RUN
    WAV_Sine_Start();
    while (true){
    }
    return 0;
}