/*
 * interface_timer.h
 *
 *  Created on: Oct 28, 2022
 *      Author: engineer
 */

#ifndef MCAL_TIMERS_INTERFACE_TIMER_H_
#define MCAL_TIMERS_INTERFACE_TIMER_H_
#include "../../lib/STD_TYPES.h"
/*fun prototypes*/
void timer_init();
void timer_setpreload(u8 copy_u8preload);
void timer_setctc(u8 copu_u8ocr);
void timer_overflow_callback (void (*ptr_overflowapp)(void));
void timer_CTC_callback (void (*ptr_ctcapp)(void));
void pwm_init();
#endif /* MCAL_TIMERS_INTERFACE_TIMER_H_ */
