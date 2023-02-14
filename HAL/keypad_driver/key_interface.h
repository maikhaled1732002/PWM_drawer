/*
 * key_interface.h
 *
 *  Created on: Oct 14, 2022
 *      Author: engineer
 */

#ifndef HAL_KEYPAD_DRIVER_KEY_INTERFACE_H_
#define HAL_KEYPAD_DRIVER_KEY_INTERFACE_H_
#include "../../MCAL/mdio/mdio_interface.h"
#include"../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#define KEY_COLUMN_PORT   MDIO_PORTC
#define KEY_ROW_PORT      MDIO_PORTC
typedef enum {
KEY_COLUMN_0_PIN,
KEY_COLUMN_1_PIN,
KEY_COLUMN_2_PIN,
KEY_COLUMN_3_PIN,

KEY_ROW_0_PIN,
KEY_ROW_1_PIN,
KEY_ROW_2_PIN,
KEY_ROW_3_PIN

}KEY_PINS;
#define KEY_NOPRESS    255
#define  KEY_PRESSED
#define KEY_COL_START      0
#define KEY_ROW_START      /* add one to real bin number for for loop*/   4
#define KEY_COL_END     4
#define KEY_ROW_END      /* add one to real bin number for for loop*/    8
void key_init();
u8 key_get ();


#endif /* HAL_KEYPAD_DRIVER_KEY_INTERFACE_H_ */
