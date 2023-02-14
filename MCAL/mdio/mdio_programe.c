/*
 * mdio_programe.c
 *
 *  Created on: Sep 24, 2022
 *      Author: engineer
 */

#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "mdio_interface.h"
#include "mdio_private.h"
void mdio_setportdirection (u8 copy_u8portnumber, u8 copy_u8portdir){
if((copy_u8portdir==PORT_OUTPUT)||(copy_u8portdir==PORT_INPUT)){
	/*valid port direction*/

	switch(copy_u8portnumber)
	{
	case MDIO_PORTA:
		DDRA=copy_u8portdir;
		break;
case MDIO_PORTB:
			DDRB=copy_u8portdir;
		break;
	case MDIO_PORTC:
				DDRC=copy_u8portdir;
			break;
	case MDIO_PORTD:
				DDRD=copy_u8portdir;
			break;
	default:
		/*wrong port number passed*/ break;

	}
}
else {
	/*not valid */
}
}


void mdio_setbindirection (u8 copy_u8binnumber,u8 copy_u8portnumber, u8 copy_u8bindir){
	if ((copy_u8binnumber>=0)&&(copy_u8binnumber<8)){
	switch(copy_u8portnumber)
	{case MDIO_PORTA:
		if (copy_u8bindir==BIN_OUTPUT) {SET_BIT(DDRA,copy_u8binnumber) ;}
		else if (copy_u8bindir==BIN_INPUT){CLR_BIT(DDRA,copy_u8binnumber);}
		else {/*invalid*/}
		break;

	case MDIO_PORTB:
			if (copy_u8bindir==BIN_OUTPUT) {SET_BIT(DDRB,copy_u8binnumber) ;}
			else if (copy_u8bindir==BIN_INPUT){CLR_BIT(DDRB,copy_u8binnumber);}
			else {/*invalid*/}
			break;

	case MDIO_PORTC:
			if (copy_u8bindir==BIN_OUTPUT) {SET_BIT(DDRC,copy_u8binnumber) ;}
			else if (copy_u8bindir==BIN_INPUT){CLR_BIT(DDRC,copy_u8binnumber);}
			else {/*invalid*/}
			break;

	case MDIO_PORTD:
			if (copy_u8bindir==BIN_OUTPUT) {SET_BIT(DDRD,copy_u8binnumber) ;}
			else if (copy_u8bindir==BIN_INPUT){CLR_BIT(DDRD,copy_u8binnumber);}
			else {/*invalid*/}
			break;

	default :
		/*wrong pin number*/
		break;


}

	}
	else {
		/*wrong bin number*/
	}


}
void mdio_setportvalue      (u8 copy_u8portnumber, u8 copy_portvalue ){

	if((copy_portvalue==PORT_HIGH)||(copy_portvalue==PORT_LOW)){
		/*valid port direction*/

		switch(copy_u8portnumber)
		{
		case MDIO_PORTA:
			PORTA=copy_portvalue;
			break;
case MDIO_PORTB:
				PORTB=copy_portvalue;
			break;
		case MDIO_PORTC:
					PORTC=copy_portvalue;
				break;
		case MDIO_PORTD:
					PORTD=copy_portvalue;
				break;
		default:
			/*wrong port number passed*/ break;

		}
	}
	else {
		/*not valid */
	}

}
void mdio_setbinvalue (u8 copy_u8binnumber,u8 copy_u8portnumber, u8 copy_u8binvalue){
	if ((copy_u8binnumber>=0)&&(copy_u8binnumber<8)){
	switch(copy_u8portnumber)
	{case MDIO_PORTA:
		if (copy_u8binvalue==BIN_HIGH) {SET_BIT(PORTA,copy_u8binnumber) ;}
		else if (copy_u8binvalue==BIN_LOW){CLR_BIT(PORTA,copy_u8binnumber);}
		else {/*invalid*/}
		break;

	case MDIO_PORTB:
			if (copy_u8binvalue==BIN_HIGH) {SET_BIT(PORTB,copy_u8binnumber) ;}
			else if (copy_u8binvalue==BIN_LOW){CLR_BIT(PORTB,copy_u8binnumber);}
			else {/*invalid*/}
			break;

	case MDIO_PORTC:
			if (copy_u8binvalue==BIN_HIGH) {SET_BIT(PORTC,copy_u8binnumber) ;}
			else if (copy_u8binvalue==BIN_LOW){CLR_BIT(PORTC,copy_u8binnumber);}
			else {/*invalid*/}
			break;

	case MDIO_PORTD:
			if (copy_u8binvalue==BIN_HIGH) {SET_BIT(PORTD,copy_u8binnumber) ;}
			else if (copy_u8binvalue==BIN_LOW){CLR_BIT(PORTD,copy_u8binnumber);}
			else {/*invalid*/}
			break;

	default :
		/*wrong por number*/
		break;


} }
	else {
		/*wrong pin number*/
	}






}

void mdio_Readport(u8 copy_u8portnumber,u8 *p_u8portreading){
	if (p_u8portreading!=NULL){
switch (copy_u8portnumber)
{
case MDIO_PORTA:
	*p_u8portreading=PINA;
	break;
case MDIO_PORTB:
	*p_u8portreading=PINB;
	break;
case MDIO_PORTC:
	*p_u8portreading=PINC;
	break;
case MDIO_PORTD:
	*p_u8portreading=PIND;
	break;

default :/*port number is wrong*/
	break ;


}
	}
	else {
	//null pointer
	}

}
void mdio_Readbin  (u8 copy_u8binnumber,u8 copy_u8portnumber, u8 * p_u8portreading ){

	if ((copy_u8binnumber>=0)&&(copy_u8binnumber<8)){
	switch(copy_u8portnumber)
	{case MDIO_PORTA:
		*p_u8portreading=GET_BIT(PINA,copy_u8binnumber);
		break;

	case MDIO_PORTB:
		*p_u8portreading=GET_BIT(PINB,copy_u8binnumber);

			break;

	case MDIO_PORTC:
		*p_u8portreading=GET_BIT(PINC,copy_u8binnumber);
			break;

	case MDIO_PORTD:
		*p_u8portreading=GET_BIT(PIND,copy_u8binnumber);
			break;

	default :
		/*wrong pin number*/
		break;


}

	}

	else {
		/*wrongnumber*/
	}

}
 void mdio_togglepin(u8 copy_u8binnumber,u8 copy_u8portnumber ){
	if ((copy_u8binnumber>=0)&&(copy_u8binnumber<8)){
	switch(copy_u8portnumber)
	{case MDIO_PORTA:
		TOGGLE_BIT(PORTA,copy_u8binnumber);
		break;

	case MDIO_PORTB:
		TOGGLE_BIT(PORTB,copy_u8binnumber);
			break;

	case MDIO_PORTC:
		TOGGLE_BIT(PORTC,copy_u8binnumber);
			break;

	case MDIO_PORTD:
		TOGGLE_BIT(PORTD,copy_u8binnumber);
			break;

	default :
		/*wrong pin number*/
		break;


}

	}

	else {
		/*wrongnumber*/
	}
}
 void mdio_setnibblevalue (u8 copy_u8pinstart, u8 copy_u8portnumber ,u8 copy_u8value){
	 u8 loc_u8value =copy_u8value;
	 //handling of the value
	 loc_u8value=((loc_u8value&(0x0f))<<copy_u8pinstart);
	if((copy_u8pinstart<=4)&&(copy_u8pinstart>0)){
	switch (	copy_u8portnumber){
	case MDIO_PORTA :
		//mask port A
		PORTA&=(~((0x0f)<<copy_u8pinstart));
		PORTA|=loc_u8value;
		break;

	case MDIO_PORTB :
		//mask port B
				PORTB&=(~((0x0f)<<copy_u8pinstart));
				PORTB|=loc_u8value;
			break;
	case MDIO_PORTC :
		//mask port C
				PORTC&=(~((0x0f)<<copy_u8pinstart));
				PORTC|=loc_u8value;
			break;
	case MDIO_PORTD :

		//mask port D
				PORTD&=(~((0x0f)<<copy_u8pinstart));
				PORTD|=loc_u8value;
				break;

	default:
		//wrong port number
		break;
	}

	}
	else {
		//wrong bin start number
	}


 }

