/* ************************************************************************** */
// Nanolay - Main Library Source File
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

#include "nanolay.h"

// FSEC
#pragma config BWRP = OFF           //Boot Segment Write-Protect bit->Boot Segment may be written
#pragma config BSS = DISABLED       //Boot Segment Code-Protect Level bits->No Protection (other than BWRP)
#pragma config BSEN = OFF           //Boot Segment Control bit->No Boot Segment
#pragma config GWRP = OFF           //General Segment Write-Protect bit->General Segment may be written
#pragma config GSS = DISABLED       //General Segment Code-Protect Level bits->No Protection (other than GWRP)
#pragma config CWRP = OFF           //Configuration Segment Write-Protect bit->Configuration Segment may be written
#pragma config CSS = DISABLED       //Configuration Segment Code-Protect Level bits->No Protection (other than CWRP)
#pragma config AIVTDIS = OFF        //Alternate Interrupt Vector Table bit->Disabled AIVT

// FBSLIM
#pragma config BSLIM = 8191         //Boot Segment Flash Page Address Limit bits->8191

// FOSCSEL
#if FOSC_4MHZ_EN
#pragma config FNOSC = FRCDIVN      //Oscillator Source Selection->Internal Fast RC (FRC) Oscillator with postscaler
#else
#pragma config FNOSC = FRC          //Oscillator Source Selection->FRC
#endif

#pragma config IESO = OFF           //Two-speed Oscillator Start-up Enable bit->Start up with user-selected oscillator source

// FOSC
#pragma config POSCMD = NONE        //Primary Oscillator Mode Select bits->Primary Oscillator disabled

#if CLKOUT_EN
#pragma config OSCIOFNC = OFF       //OSC2 Pin Function bit->OSC2 is clock output
#else
#pragma config OSCIOFNC = ON        //OSC2 Pin Function bit->OSC2 is GPIO
#endif

#pragma config FCKSM = CSECME       //Clock Switching Mode bits->Both Clock switching and Fail-safe Clock Monitor are enabled
#pragma config PLLKEN = ON          //PLL Lock Status Control->PLL lock signal will be used to disable PLL clock output if lock is lost
#pragma config XTCFG = G3           //XT Config->24-32 MHz crystals
#pragma config XTBST = ENABLE       //XT Boost->Boost the kick-start

// FWDT
#pragma config RWDTPS = PS1         //Run Mode Watchdog Timer Post Scaler select bits->1:1
#pragma config RCLKSEL = LPRC       //Watchdog Timer Clock Select bits->Always use LPRC
#pragma config WINDIS = OFF         //Watchdog Timer Window Enable bit->Watchdog Timer in Window mode
#pragma config WDTWIN = WIN25       //Watchdog Timer Window Select bits->WDT Window is 25% of WDT period
#pragma config SWDTPS = PS1         //Sleep Mode Watchdog Timer Post Scaler select bits->1:1
#pragma config FWDTEN = ON_SW       //Watchdog Timer Enable bit->WDT controlled via SW, use WDTCON.ON bit

// FPOR
#pragma config BISTDIS = DISABLED   //Memory BIST Feature Disable->mBIST on reset feature disabled

// FICD
#pragma config ICS = PGD2           //ICD Communication Channel Select bits->Communicate on PGC2 and PGD2
#pragma config JTAGEN = OFF         //JTAG Enable bit->JTAG is disabled
#pragma config NOBTSWP = DISABLED   //BOOTSWP instruction disable bit->BOOTSWP instruction is disabled

// FDMTIVTL
#pragma config DMTIVTL = 0          //Dead Man Timer Interval low word->0

// FDMTIVTH
#pragma config DMTIVTH = 0          //Dead Man Timer Interval high word->0

// FDMTCNTL
#pragma config DMTCNTL = 0          //Lower 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF)->0

// FDMTCNTH
#pragma config DMTCNTH = 0          //Upper 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF)->0

// FDMT
#pragma config DMTDIS = OFF         //Dead Man Timer Disable bit->Dead Man Timer is Disabled and can be enabled by software

// FDEVOPT
#pragma config ALTI2C1 = OFF        //Alternate I2C1 Pin bit->I2C1 mapped to SDA1/SCL1 pins
#pragma config ALTI2C2 = OFF        //Alternate I2C2 Pin bit->I2C2 mapped to SDA2/SCL2 pins
#pragma config ALTI2C3 = OFF        //Alternate I2C3 Pin bit->I2C3 mapped to SDA3/SCL3 pins
#pragma config SMBEN = SMBUS        //SM Bus Enable->SMBus input threshold is enabled
#pragma config SPI2PIN = PPS        //SPI2 Pin Select bit->SPI2 uses I/O remap (PPS) pins

// FALTREG
#pragma config CTXT1 = OFF          //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits->Not Assigned
#pragma config CTXT2 = OFF          //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits->Not Assigned
#pragma config CTXT3 = OFF          //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 3 bits->Not Assigned
#pragma config CTXT4 = OFF          //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 4 bits->Not Assigned

// FBTSEQ
#pragma config BSEQ = 4095          //Relative value defining which partition will be active after device Reset; the partition containing a lower boot number will be active->4095
#pragma config IBSEQ = 4095         //The one's complement of BSEQ; must be calculated by the user and written during device programming.->4095

// FBOOT
#pragma config BTMODE = SINGLE      //Device Boot Mode Configuration->Device is in Single Boot (legacy) mode


Clock_Freq MasterClock;

void Sys_ClockSet(Clock_Freq clk){
    MasterClock = clk;

    switch ( clk ){
        // case FOSC_4MHZ: 
        //     CLKDIV = 0x3101;                                                    // FRCDIV FRC/2; PLLPRE 1; DOZE 1:8; DOZEN disabled; ROI disabled;
        //     PLLFBD = 0x96;                                                      // PLLFBDIV 150;
        //     PLLDIV = 0x41;                                                      // POST1DIV 1:4; VCODIV FVCO/4; POST2DIV 1:1;  
        //     break;
        case FOSC_8MHZ:
            CLKDIV = 0x3001;                                                    // FRCDIV FRC/1; PLLPRE 1; DOZE 1:8; DOZEN disabled; ROI disabled;  
            PLLFBD = 0x7D;                                                      // PLLFBDIV 125;
            PLLDIV = 0x41;                                                      // POST1DIV 1:4; VCODIV FVCO/4; POST2DIV 1:1; 
            break;
        case FOSC_20MHZ:
            CLKDIV = 0x3001;                                                    // FRCDIV FRC/1; PLLPRE 1; DOZE 1:8; DOZEN disabled; ROI disabled; 
            PLLFBD = 0x7D;                                                      // PLLFBDIV 125; 
            PLLDIV = 0x55;                                                      // POST1DIV 1:5; VCODIV FVCO/4; POST2DIV 1:5;
            break;
        case FOSC_50MHZ:
            CLKDIV = 0x3001;                                                    // FRCDIV FRC/1; PLLPRE 1; DOZE 1:8; DOZEN disabled; ROI disabled;
            PLLFBD = 0x7D;                                                      // PLLFBDIV 125;   
            PLLDIV = 0x52;                                                      // POST1DIV 1:5; VCODIV FVCO/4; POST2DIV 1:2;
            break;
        case FOSC_100MHZ:
            CLKDIV = 0x3001;                                                    // FRCDIV FRC/1; PLLPRE 1; DOZE 1:8; DOZEN disabled; ROI disabled;
            PLLFBD = 0x7D;                                                      // PLLFBDIV 125;   
            PLLDIV = 0x51;                                                      // POST1DIV 1:5; VCODIV FVCO/4; POST2DIV 1:1;
            break;
        default:
            break;
    }

    ACLKCON1 = 0x8101;                                                          // APLLEN enabled; FRCSEL FRC; APLLPRE 1:1; 
    APLLFBD1 = 0xC8;                                                            // APLLFBDIV 200;
    APLLDIV1 = 0x41;                                                            // APOST1DIV 1:4; APOST2DIV 1:1; AVCODIV FVCO/4; 
    OSCTUN = 0x00;                                                              // TUN Center frequency;  
    REFOCONL = 0x00;                                                            // ROEN disabled; ROSWEN disabled; ROSLP disabled; ROSEL FOSC; ROOUT disabled; ROSIDL disabled;
    REFOCONH = 0x00;                                                            // RODIV 0; 
    REFOTRIMH = 0x00;                                                           // ROTRIM 0; 
    RPCON = 0x00;                                                               // IOLOCK disabled;
    PMDCON = 0x00;                                                              // PMDLOCK disabled;

    // if ( MasterClock == FOSC_4MHZ ){                                            // CF no clock failure; NOSC FRCDIV; CLKLOCK unlocked; OSWEN Switch is Complete;
    //     __builtin_write_OSCCONH((uint_fast8_t) (0x07));
    //     __builtin_write_OSCCONL((uint_fast8_t) (0x00));
    // }
    // else if ( MasterClock == FOSC_8MHZ ){                                       // CF no clock failure; NOSC FRC; CLKLOCK unlocked; OSWEN Switch is Complete;
    if ( MasterClock == FOSC_8MHZ ){                                            // CF no clock failure; NOSC FRC; CLKLOCK unlocked; OSWEN Switch is Complete; 
        __builtin_write_OSCCONH((uint_fast8_t) (0x00));
        __builtin_write_OSCCONL((uint_fast8_t) (0x00));        
    }
    else {                                                                      // CF no clock failure; NOSC FRCPLL; CLKLOCK unlocked; OSWEN Switch is Complete; 
        __builtin_write_OSCCONH((uint_fast8_t) (0x01));
        __builtin_write_OSCCONL((uint_fast8_t) (0x01));
        while (OSCCONbits.OSWEN != 0);                                          // Wait for Clock switch to occur
        while (OSCCONbits.LOCK != 1);                                           // Wait for Clock switch to occur
    }    
    WDTCONLbits.ON = 0;                                                         // Disable Watchdog Timer 
}


Clock_Freq Sys_GetMasterClkFreq(void){
    return MasterClock;
}


void Sys_DisableAllPeripherals(void) {
    PMD1 = 0xFFFF;
    PMD2 = 0xFFFF;
    PMD3 = 0xFFFF;
    PMD4 = 0xFFFF;
    PMD6 = 0xFFFF;
    PMD7 = 0xFFFF;
    PMD8 = 0xFFFF;
}


void Sys_Init(Clock_Freq clk){
    GPIO_Init();
    if ( CLKOUT_EN ) {                                                          // required to set GPIO here prior to setting clock frequency
        GPIO_SetPortBPin(PIN1, OUTPUT, false, false, false);
    }
    Sys_ClockSet( clk );
    Sys_DisableAllPeripherals();
}