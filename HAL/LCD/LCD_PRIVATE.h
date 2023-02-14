/*
 * LCD_PRIVATE.h
 *
 *  Created on: Oct 14, 2022
 *      Author: engineer
 */

/*
 * LCD_PRIVATE.H
 *
 *  Created on: Oct 1, 2022
 *      Author: engineer
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_
//options for fun sets
#define FUNCTION_SET_4BIT_MODE_1LINE_5BY8_SIZE   0b00100000
#define FUNCTION_SET_4BIT_MODE_1LINE_5BY11_SIZE  0b00100100
#define FUNCTION_SET_4BIT_MODE_2LINE_5BY8_SIZE   0b00101000
#define FUNCTION_SET_4BIT_MODE_2LINE_5BY11_SIZE  0b00101100
//options for display command
#define DISPLAY_OFF_COMMAND                      0b00001000
#define DISPLAY_ON_COMMAND                       0b00001100
#define DISPLAY_ON_CUSROR                        0b00001110
#define DISPLAY_ON_CURSOR_BLINK_ON               0b00001111
//clear dispaly command
#define CLEAR_DISPLAY                            0b00000001
// options for entery mode
#define ENTRY_MODE_INC_NO_SHIFT                  0b00000110
#define       ENTRY_MODE_INC_WITH_SHIFT          0b00000111
#define       ENTRY_MODE_DEC_NO_SHIFT          0b00000100
#define       ENTRY_MODE_DEC_WITH_SHIFT           0b00000101
#define LINE_0_OFFSET   128
#define LINE_1_OFFSET   192
#endif /* HAL_LCD_LCD_PRIVATE_H_ */

