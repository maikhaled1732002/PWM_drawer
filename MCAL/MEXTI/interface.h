/*
 * interface.h
 *
 *  Created on: Oct 21, 2022
 *      Author: engineer
 */

#ifndef MCAL_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_INTERFACE_H_

/*functions prtotypes*/
void MEXTI0_init();
void MEXTI1_init();
void MEXTI2_init();

void MEXIT_setsensecontrol(u8 copy_u8interrupt , u8 mode);

void MEXIT_callback(void(*loc_Ptrtofun)(void));

#endif /* MCAL_MEXTI_INTERFACE_H_ */
