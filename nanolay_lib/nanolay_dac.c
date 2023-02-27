/* ************************************************************************** */
// Nanolay - DAC Library Source File
//
// Description:     Custom dsPIC33CK library for DAC functions. Should be
//                  included in the nanolay.h file
//
// Target Device:   dsPIC33CKxxxMP202  
//
// Author:          Mark Angelo Tarvina (mttarvina)
// Email:           mttarvina@gmail.com
// Revision:        1.0
// Last Updated:    25.Feb.23
/* ************************************************************************** */

#include "nanolay_dac.h"

DAC_Stat stat;


void DAC_Init(bool activeOnIdle){           
    Clock_Freq clk = Sys_GetMasterClkFreq();

    if ((clk != FOSC_8MHZ)) {
		PMD7bits.CMP1MD = 0;													// enable CMP1 module

	    DACCTRL1L = 0x00; 														// CLKDIV 1:1; DACON disabled; DACSIDL disabled; FCLKDIV 1:1; CLKSEL AFVCO/2 - Auxiliary VCO Clock;        
		DACCTRL1Lbits.DACSIDL = !activeOnIdle;
	    DACCTRL2L = 0x55; 														// TMODTIME 85; 
	    DACCTRL2H = 0x8A; 														// SSTIME 138; 
	    DAC1CONH = 0x00; 														// TMCB 0; 
	    DAC1CONL = 0x00; 

	    //Slope Settings
	    SLP1CONH = 0x00; 														// HME disabled; PSE Negative; SLOPEN disabled; TWME disabled; 
	    SLP1CONL = 0x00; 														// HCFSEL None; SLPSTRT None; SLPSTOPB None; SLPSTOPA None; 
	    SLP1DAT = 0x00; 														// SLPDAT 0; 
	    DAC1DATL = 0x00; 														// DACDATL 0; 
	    DAC1DATH = 0x00; 														// DACDATH 0; 
    
		DAC1CONLbits.DACEN	= 1;												
		DAC1CONLbits.DACOEN = 1;    											// enable DACOUT pin

        DACCTRL1Lbits.DACON = 1;												// enable DAC modules
		stat.dac1En = true;
	}
}


void DAC_Write(uint_fast16_t val){
    if (val < MIN_DAC_VAL){
		DAC1DATHbits.DACDAT = MIN_DAC_VAL;
		return;
	}
	else if (val > MAX_DAC_VAL){
		DAC1DATHbits.DACDAT = MAX_DAC_VAL;
		return;
	}
	else {
		DAC1DATHbits.DACDAT = val;
		return;
	}
}


