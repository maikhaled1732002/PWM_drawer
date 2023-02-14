/*
 * programe.c
 *
 *  Created on: Oct 21, 2022
 *      Author: engineer
 */
/*
 *
 * */
#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../../MCAL/mdio/mdio_interface.h"
#include"../MEXTI/private.h"
#include"config.h"
//GLOBAL pointer to function  to not violate the layer arch
void (*Gptr)(void)=NULL;
void MEXIT_callback(void(loc_Ptrtofun)(void)){
	if(loc_Ptrtofun!=NULL){
		Gptr=loc_Ptrtofun;
	}

}
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if(Gptr!=NULL){


		Gptr();
}
}

void MEXTI0_init(){
#if sense_control_state  ==MEXTI_LOW_LEVEL

	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif 	sense_control_state == MEXTI_ANY_LOGICAL_LEVEL
	SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
#elif 	sense_control_state == MEXTI_RISING_LEVEL
		CLR_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);
#elif 	sense_control_state == MEXTI_FALLING_LEVEL
				SET_BIT(MCUCR,0);
								SET_BIT(MCUCR,1);
#endif
 SET_BIT(GICR,6);
}
void MEXTI1_init(){}
void MEXTI2_init(){}
