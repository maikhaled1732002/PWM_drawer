/*
 * mido_interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: engineer
 */

#ifndef MDIO_MDIO_INTERFACE_H_
#define MDIO_MDIO_INTERFACE_H_
#include "../../lib/STD_TYPES.h"
/*putting descriptive names for different objects */
#define MDIO_PORTA   0
#define MDIO_PORTB   1
#define MDIO_PORTC   2
#define MDIO_PORTD   3

#define PORT_OUTPUT  255
#define PORT_INPUT   0

#define  BIN_OUTPUT   1
#define  BIN_INPUT    0

#define PORT_HIGH    255
#define PORT_LOW     0

#define BIN_HIGH    1
#define BIN_LOW     0

#define NULL      0
typedef enum
{
PIN0,
PIN1,
PIN2,
PIN3,
PIN4,
PIN5,
PIN6,
PIN7
}pin_t;


/*function prototypes*/
void mdio_setportdirection ( u8  copy_u8portnumber, u8 copy_u8portdir);

void mdio_setbindirection (u8 copy_u8binnumber,u8 copy_u8portnumber, u8 copy_u8bindir);
void mdio_setportvalue      (u8 copy_u8portnumber, u8 copy_portvalue );
void mdio_setbinvalue (u8 copy_u8binnumber,u8 copy_u8portnumber, u8 copy_u8binvalue);
void mdio_Readport(u8 copy_u8portnumber,u8 *p_u8portreading);
void mdio_Readbin  (u8 copy_u8binnumber,u8 copy_u8portnumber, u8 *p_u8portreading );
void mdio_togglepin (u8 copy_u8binnumber,u8 copy_u8portnumber );
void mdio_setnibblevalue (u8 copy_u8pinstart, u8 copy_u8portnumber ,u8 copy_u8value);


#endif /* MDIO_MDIO_INTERFACE_H_ */
