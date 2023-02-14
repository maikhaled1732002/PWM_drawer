/*
 * key_programe.c
 *
 *  Created on: Oct 14, 2022
 *      Author: engineer
 */

#include "../../MCAL/mdio/mdio_interface.h"
#include"../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include"key_interface.h"
#include"key_private.h"
//#include"key_private.h"

void key_init(){
/*SET bins direction */
	mdio_setbindirection (KEY_COLUMN_0_PIN,KEY_COLUMN_PORT, BIN_OUTPUT);
	mdio_setbindirection (KEY_COLUMN_1_PIN,KEY_COLUMN_PORT, BIN_OUTPUT);
	mdio_setbindirection (KEY_COLUMN_2_PIN,KEY_COLUMN_PORT, BIN_OUTPUT);
	mdio_setbindirection (KEY_COLUMN_3_PIN,KEY_COLUMN_PORT, BIN_OUTPUT);
	mdio_setbindirection (KEY_ROW_0_PIN,KEY_ROW_PORT, BIN_INPUT);
	mdio_setbindirection (KEY_ROW_1_PIN,KEY_ROW_PORT, BIN_INPUT);
	mdio_setbindirection (KEY_ROW_2_PIN,KEY_ROW_PORT, BIN_INPUT);
	mdio_setbindirection (KEY_ROW_3_PIN,KEY_ROW_PORT, BIN_INPUT);
	/*activate pull up resistor */
	mdio_setbinvalue (KEY_ROW_0_PIN,KEY_ROW_PORT,BIN_HIGH);
	mdio_setbinvalue (KEY_ROW_1_PIN,KEY_ROW_PORT,BIN_HIGH);
	mdio_setbinvalue (KEY_ROW_2_PIN,KEY_ROW_PORT,BIN_HIGH);
	mdio_setbinvalue (KEY_ROW_3_PIN,KEY_ROW_PORT,BIN_HIGH);
/* deactivate all cloumns*/
	mdio_setbinvalue (KEY_COLUMN_0_PIN,KEY_COLUMN_PORT,BIN_HIGH);
	mdio_setbinvalue (KEY_COLUMN_0_PIN,KEY_COLUMN_PORT,BIN_HIGH);
	mdio_setbinvalue (KEY_COLUMN_0_PIN,KEY_COLUMN_PORT,BIN_HIGH);
	mdio_setbinvalue (KEY_COLUMN_0_PIN,KEY_COLUMN_PORT,BIN_HIGH);

}
u8 key_get ()
{
		u8 loc_u8column_count =0;
		u8 loc_u8row_count =0;
		u8 loc_returnvalue  =KEY_NOPRESS ;
		u8  loc_u8binstate=0;
		for(loc_u8column_count=KEY_COL_START;loc_u8column_count<KEY_COL_END;loc_u8column_count++){
			//activate colum
			mdio_setbinvalue(loc_u8column_count,KEY_COLUMN_PORT,BIN_LOW);
				for (loc_u8row_count=KEY_ROW_START;loc_u8row_count<KEY_ROW_END;loc_u8row_count++){
					mdio_Readbin (loc_u8row_count,KEY_ROW_PORT,&loc_u8binstate);
					if (loc_u8binstate==0)
					{ //return the key value
						loc_returnvalue=KEY_SWITCH_VALUES[loc_u8column_count-KEY_COL_START][loc_u8row_count-KEY_ROW_START] ;
						while(loc_u8binstate==0){
							mdio_Readbin (loc_u8row_count,KEY_ROW_PORT,&loc_u8binstate);
						}
						//further update :put a delay here

					}
					else {

					}
				}
			//deactivate the column
				mdio_setbinvalue(loc_u8column_count,KEY_COLUMN_PORT,BIN_HIGH);
		}
	return 	loc_returnvalue;
}
/*u8 key_get (){

}*/
