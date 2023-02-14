/*
 * LCD_PROGRAME.c
 *
 *  Created on: Oct 14, 2022
 *      Author: engineer
 */


/*
 * LCD_PROGRAME.C
 *
 *  Created on: Oct 1, 2022
 *      Author: engineer
 */
#include "util/delay.h"
#include "../../MCAL/mdio/mdio_interface.h"
#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "LCD_CONFIG.h"

#include "LCD_INTERFACE.h"
void lcd_writecmd(u8 copy_u8command)
{

	//set rw to zero
	mdio_setbinvalue(RW,CONTROL_PORT,BIN_LOW);
	//set rs to zero
	mdio_setbinvalue(RS,CONTROL_PORT,BIN_LOW);
// set high nibble value to command
	mdio_setnibblevalue(LCD_PIN_START,DATA_PORT,copy_u8command>>4);
	//the falling edge of enable
	mdio_setbinvalue(E,CONTROL_PORT,BIN_HIGH);
	_delay_ms(2);
	mdio_setbinvalue(E,CONTROL_PORT,BIN_LOW);

	mdio_setnibblevalue(LCD_PIN_START,DATA_PORT,copy_u8command);
	//the falling edge of enable
		mdio_setbinvalue(E,CONTROL_PORT,BIN_HIGH);
		_delay_ms(2);
		mdio_setbinvalue(E,CONTROL_PORT,BIN_LOW);

}
void lcd_init4bit(){
_delay_ms(30);
u8 loc_u8counter=0;
//set direction of the used pins
for(loc_u8counter =LCD_PIN_START;loc_u8counter<(LCD_PIN_START+4) ;loc_u8counter++ ){

	mdio_setbindirection (loc_u8counter,DATA_PORT,BIN_OUTPUT);
}
//set dir of control bins

mdio_setbindirection (RS,CONTROL_PORT,BIN_OUTPUT);
mdio_setbindirection (RW,CONTROL_PORT,BIN_OUTPUT);
mdio_setbindirection (E,CONTROL_PORT,BIN_OUTPUT);
//send high nibble of the fun set as datasheet said
mdio_setnibblevalue(LCD_PIN_START,DATA_PORT,FUN_SET_MODE>>4);
mdio_setbinvalue(E,CONTROL_PORT,BIN_HIGH);
	_delay_ms(2);
	mdio_setbinvalue(E,CONTROL_PORT,BIN_LOW);
/* start of init sequence */
//send fun set command
lcd_writecmd(FUN_SET_MODE);

// send display on/off command
_delay_ms(1);
lcd_writecmd(DISPLAY_COMMAND );

//display clear
_delay_ms(1);
lcd_writecmd(CLEAR_DISPLAY  );


//send entery mode
_delay_ms(2);
lcd_writecmd(ENTRY_MODE_COMMAND   );
}
void lcd_writechar4bit (u8 copy_u8data){
	//set rw to zero
		mdio_setbinvalue(RW,CONTROL_PORT,BIN_LOW);
		//set rs to high to write data
		mdio_setbinvalue(RS,CONTROL_PORT,BIN_HIGH);
	// set high nibble value to command
		mdio_setnibblevalue(LCD_PIN_START,DATA_PORT,copy_u8data>>4);
		//the falling edge of enable
		mdio_setbinvalue(E,CONTROL_PORT,BIN_HIGH);
		_delay_ms(2);
		mdio_setbinvalue(E,CONTROL_PORT,BIN_LOW);

		mdio_setnibblevalue(LCD_PIN_START,DATA_PORT,copy_u8data);
		//the falling edge of enable
			mdio_setbinvalue(E,CONTROL_PORT,BIN_HIGH);
			_delay_ms(2);
			mdio_setbinvalue(E,CONTROL_PORT,BIN_LOW);
};
void lcd_setposition (u8 line_no , u8 pos_no){
if((line_no== LCD_LINE_0)||(line_no== LCD_LINE_1)){
if(pos_no<16){
if(line_no== LCD_LINE_0){
	lcd_writecmd(pos_no+LINE_0_OFFSET);
}
else {
	lcd_writecmd(pos_no+LINE_1_OFFSET);
}
}
else {
	//wrong line
}
}
};
void lcd_writestring (u8*copy_u8data){

for(u8 i=0 ;copy_u8data[i]!='\0';i++){
	lcd_writechar4bit ( copy_u8data[i]);
}

};
void lcd_writenumber (u8 copy_u8number){

u8 new_no =0;
 u8 real_no =0;
 real_no=copy_u8number;
while (copy_u8number>0){

	new_no=real_no%10;
			lcd_writechar4bit ( new_no);
			real_no=real_no/10;


}

};
