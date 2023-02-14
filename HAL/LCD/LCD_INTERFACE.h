/*
 * LCD_INTERFACE.h
 *
 *  Created on: Oct 14, 2022
 *      Author: engineer
 */

/*
 * LCD_INTERFACE.h
 *
 *  Created on: Oct 1, 2022
 *      Author: engineer
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include "../../MCAL/mdio/mdio_interface.h"
#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../../MCAL/mdio/mdio_interface.h"
#include "LCD_CONFIG.h"
#define RS   0
#define RW    1
# define E    2
#define  LCD_PIN_START    4
#define CONTROL_PORT  MDIO_PORTB
//macros for users
#define LCD_LINE_0      0
#define LCD_LINE_1      1

#define  DATA_PORT    MDIO_PORTA
void lcd_init4bit();
void lcd_writecmd(u8 copy_u8command);
void lcd_writechar4bit (u8 copy_u8data);
void lcd_setposition (u8 line_no , u8 pos_no);
void lcd_writestring (u8*copy_u8data);
void lcd_writenumber (u8 copy_u8number);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */

