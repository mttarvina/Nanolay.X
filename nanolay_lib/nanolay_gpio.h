/* ************************************************************************** */
// Nanolay - GPIO Library Header File
//
// Description:     Custom dsPIC33CK library for GPIO functions. Should be
//                  included in the nanolay.h file
//
// Target Device:   dsPIC33CKxxxMP202  
//
// Author:          Mark Angelo Tarvina (~tarvs)
// Email:           mttarvina@gmail.com
// Revision:        1.0
// Last Updated:    25.Feb.2023
/* ************************************************************************** */

#ifndef _NANOLAY_GPIO_H
#define	_NANOLAY_GPIO_H


#include "nanolay.h"


#define LOW     false
#define HIGH    true


typedef enum gpio_state {
    OUTPUT = 0,
    INPUT = 1
} GPIO_State;


typedef enum gpio_edgeType {
    FALLING = 0,
    RISING = 1,
    ANY = 2
} GPIO_EdgeType;


typedef enum gpio_port {
    PORT_A = 0x0,
    PORT_B = 0x1
} GPIO_Port;

typedef enum  gpio_pin {
    PIN0 = 0x0001,
    PIN1 = 0x0002,
    PIN2 = 0x0004,
    PIN3 = 0x0008,
    PIN4 = 0x0010,
    PIN5 = 0x0020,
    PIN6 = 0x0040,
    PIN7 = 0x0080,
    PIN8 = 0x0100,
    PIN9 = 0x0200,
    PIN10 = 0x0400,
    PIN11 = 0x0800,
    PIN12 = 0x1000,
    PIN13 = 0x2000,
    PIN14 = 0x4000,
    PIN15 = 0x8000
} GPIO_Pin;



// *****************************************************************************
// @desc:       Sets the default GPIO setting for all pins, at startup, as INPUT
//                  This is called by Sys_Init()
// @args:       None
// @returns:    None
// *****************************************************************************
void GPIO_Init(void);


// *****************************************************************************
// @desc:       Set any PORTA pin as INPUT or OUTPUT, enable/disable opendrain,
//                  internal pullup, and/or internal pulldown resistors
// @args:       pin [GPIO_Pin]: PINx
//              dir [GPIO_State]: OUTPUT or INPUT
//              opendrain [bool]: true = enable
//              pullup [bool]: true = enable
//              pulldown [bool]: true = enable
// @returns:    None
// *****************************************************************************
void GPIO_SetPortAPin(GPIO_Pin pin, GPIO_State dir, bool opendrain, bool pullup, bool pulldown);


// *****************************************************************************
// @desc:       Set any PORTB pin as INPUT or OUTPUT, enable/disable opendrain,
//                  internal pullup, and/or internal pulldown resistors
// @args:       pin [GPIO_Pin]: PINx
//              dir [GPIO_State]: OUTPUT or INPUT
//              opendrain [bool]: true = enable
//              pullup [bool]: true = enable
//              pulldown [bool]: true = enable
// @returns:    None
// *****************************************************************************
void GPIO_SetPortBPin(GPIO_Pin pin, GPIO_State dir, bool opendrain, bool pullup, bool pulldown);


// *****************************************************************************
// @desc:       Set any PORTA pin to output HIGH or LOW. This is similar to
//                  Arduino's DigitalWrite() function
// @args:       pin [GPIO_Pin]: PINx
//              state [bool]: HIGH or LOW
// @returns:    None
// *****************************************************************************
void GPIO_DrivePortAPin(GPIO_Pin pin, bool state);


// *****************************************************************************
// @desc:       Set any PORTB pin to output HIGH or LOW. This is similar to
//                  Arduino's DigitalWrite() function
// @args:       pin [GPIO_Pin]: PINx
//              state [bool]: HIGH or LOW
// @returns:    None
// *****************************************************************************
void GPIO_DrivePortBPin(GPIO_Pin pin, bool state);


// *****************************************************************************
// @desc:       Attach an interrupt to any PORTA pin
// @args:       pin [GPIO_Pin]: PINx
//              edge [GPIO_EdgeType]: RISING or FALLING
//              InterruptHandler [func pointer]: An interrupt callback function 
// @returns:    None
// *****************************************************************************
void GPIO_SetPortAInterrupt(GPIO_Pin pin, GPIO_EdgeType edge, void (* InterruptHandler)(void));


// *****************************************************************************
// @desc:       Attach an interrupt to any PORTB pin
// @args:       pin [GPIO_Pin]: PINx
//              edge [GPIO_EdgeType]: RISING or FALLING
//              InterruptHandler [func pointer]: An interrupt callback function 
// @returns:    None
// *****************************************************************************
void GPIO_SetPortBInterrupt(GPIO_Pin pin, GPIO_EdgeType edge, void (* InterruptHandler)(void));

#endif // _NANOLAY_GPIO_H