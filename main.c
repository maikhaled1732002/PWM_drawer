/*
 * main.c
 *
 *  Created on: Feb 13, 2023
 *      Author: engineer
 */
#include"util/delay.h"
#include"lib/BIT_MATH.h"
#include"lib/STD_TYPES.h"
#include "MCAL/timers/interface_timer.h"
#include "MCAL/MGIE/interface.h"
#include "MCAL/mdio/mdio_interface.h"
#include "HAL/LCD/LCD_INTERFACE.h"

int main ()
{ // tperiod =0.016;
u8  freq[10] ="F=62.5hz " ;//1/tov =1/2^res *ticktime
// ton =0.008;
u8  duty[10]="D=50%";
 u8 D=80; //duty cycle number
 pwm_init();
	 lcd_init4bit();
	 mdio_setbindirection (PIN3,MDIO_PORTB , BIN_OUTPUT); /*set OC0 pin as output*/
//	lcd_writechar4bit ('m');
//lcd_writenumber (172);

 lcd_writestring (freq);
 		lcd_writestring (duty);
 		lcd_setposition (1 , 0);

 while(1){
//make a pwm with duty cylce =50%
		/*ocr0 =dutycycle*2^res
		so to make duty 50% ,makce ocro =127
		*/
timer_setctc(127);
u8 counter1 =D/10;//first counter for first half cycle
u8 counter2 =10-counter1;//second counter for second half cycle
lcd_writestring (freq);
		lcd_writestring (duty);
		lcd_setposition (1 , 0);
		for(u8 i=0;i<counter1;i++){
		lcd_writechar4bit ('_');
}
		lcd_writechar4bit ('|');

		for(u8 x=0;x<counter2;x++){
		lcd_writechar4bit ('-');
}
		lcd_writechar4bit ('|');


		for(u8 i=0;i<counter1;i++){
		lcd_writechar4bit ('_');
}
		lcd_writechar4bit ('|');
		for(u8 x=0;x<counter2;x++){
		lcd_writechar4bit ('-');
}
		lcd_writechar4bit ('|');

	}





	return 0;
}
