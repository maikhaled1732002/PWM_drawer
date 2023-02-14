/*
 * key_private.h
 *
 *  Created on: Oct 14, 2022
 *      Author: engineer
 */

#ifndef HAL_KEYPAD_DRIVER_KEY_PRIVATE_H_
#define HAL_KEYPAD_DRIVER_KEY_PRIVATE_H_
#include"../../lib/STD_TYPES.h"
u8 KEY_SWITCH_VALUES[4][4]={
		{'1',
		'4',
		'7',
		'*'},
		{
		'2',
		'5',
		'8',
	    '0'
		},
		{'3',
		'6',
		'9',
		'#'
		},
		{
			'A',
			'B',
			'C',
			'D'
		}
};

#endif /* HAL_KEYPAD_DRIVER_KEY_PRIVATE_H_ */
