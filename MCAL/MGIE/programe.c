/*
 * programe.c
 *
 *  Created on: Oct 21, 2022
 *      Author: engineer
 */
#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../../MCAL/mdio/mdio_interface.h"
#include "../MGIE/private.h"
void MGIE_enable(void){

	SET_BIT(SREG,7 );



}
void MGIE_disable(void){

CLR_BIT(SREG,7);

}
