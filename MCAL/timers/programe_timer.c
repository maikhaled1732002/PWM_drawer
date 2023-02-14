/*
 * programe_timer.c
 *
 *  Created on: Oct 28, 2022
 *      Author: engineer
 */
#include "../../lib/STD_TYPES.h"
#include"interface_timer.h"
#include "../../lib/BIT_MATH.h"

#include "../../MCAL/mdio/mdio_interface.h"
#include "config_timer.h"
#include "private_timer.h"

// two global ptr
void(*glob_overflowisr_ptr)(void)=NULL;
void(*glob_ctcisr_ptr)(void)=NULL;

/*
 * *set mode
 * set ocomode
 * set interrupt state
 * set prescalar
 *
 */
void pwm_init(){
	//fast pwm mode non inverting

	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
}
void timer_init(){

//SETMODE OF TIMER
#if TIMER0_MODE ==TIMER_NORMAL_MODE
CLR_BIT(TCCR0,3);
CLR_BIT(TCCR0,6);
//set interrupt state
#if TIMER0_NORMAL_MODE_INTERRUPT ==NORMAL_INTERRUPT_DISENABLED
CLR_BIT(TIMSK,0);

#elif TIMER0_NORMAL_MODE_INTERRUPT   NORMAL_INTERRUPT_ENABLED
SET_BIT(TIMSK,0);
#endif


#elif TIMER0_MODE ==TIMER_CTC_MODE

SET_BIT(TCCR0,3);
CLR_BIT(TCCR0,6);
//set interrupt state
#if TIMER0_CTC_MODE_INTERRUPT ==CTC_INTERRUPT_DISENABLED
CLR_BIT(TIMSK,1);

#elif TIMER0_CTC_MODE_INTERRUPT  == CTC_INTERRUPT_ENABLED
SET_BIT(TIMSK,1);
#endif




#if  OC0_MODE ==OC0_PIN_DISCONNECTED
CLR_BIT(TCCR0,4);
CLR_BIT(TCCR0,5);
#elif   OC0_MODE ==OC0_PIN_TOGGLE
SET_BIT(TCCR0,4);
CLR_BIT(TCCR0,5);
#elif   OC0_MODE ==OC0_PIN_CLEARED
CLR_BIT(TCCR0,4);
SET_BIT(TCCR0,5);
#elif   OC0_MODE ==OC0_PIN_SET
SET_BIT(TCCR0,4);
SET_BIT(TCCR0,5);
#endif

#elif TIMER0_MODE ==TIMER_PHASE_CORRECT_MODE
CLR_BIT(TCCR0,3);
SET_BIT(TCCR0,6);
//set pwm wave on oc
#if TIMER_PHASE_CORRECT_MODE ==PHASE_CORRECT_OC0_DISCONNECTED
CLR_BIT(TCCR0,4);
CLR_BIT(TCCR0,5);
#elif TIMER_PHASE_CORRECT_MODE ==PHASE_CORRECT_OC0_NON_INVERTING
CLR_BIT(TCCR0,4);
SET_BIT(TCCR0,5);
#elif TIMER_PHASE_CORRECT_MODE ==PHASE_CORRECT_OC0_INVERTING
SET_BIT(TCCR0,4);
SET_BIT(TCCR0,5);
#endif

#elif TIMER0_MODE ==TIMER_FAST_PWM_MODE
SET_BIT(TCCR0,3);
SET_BIT(TCCR0,6);
//set pwm wave on oc
#if TIMER_FAST_PWM_MODE_CONDITION ==FAST_PWM_OC0_DISCONNECTED
CLR_BIT(TCCR0,4);
CLR_BIT(TCCR0,5);
#elif TIMER_FAST_PWM_MODE_CONDITION ==FAST_PWM_OC0_NON_INVERTING
CLR_BIT(TCCR0,4);
SET_BIT(TCCR0,5);
#elif TIMER_FAST_PWM_MODE_CONDITION ==FAST_PWM_OC0_INVERTING
SET_BIT(TCCR0,4);
SET_BIT(TCCR0,5);
#endif

#else
#error"wrong mode chosen"
#endif


//set prescalar
#if CLK_SOURCE_MODE==NO_CLK_SOURCE
CLR_BIT(TCCR0,0);
CLR_BIT(TCCR0,1);
CLR_BIT(TCCR0,2);
#elif CLK_SOURCE_MODE==SYSTEM_CLK
SET_BIT(TCCR0,0);
CLR_BIT(TCCR0,1);
CLR_BIT(TCCR0,2);
#elif CLK_SOURCE_MODE==PRESCALAR_OVER_8
CLR_BIT(TCCR0,0);
SET_BIT(TCCR0,1);
CLR_BIT(TCCR0,2);
#elif CLK_SOURCE_MODE==PRESCALAR_OVER_64
SET_BIT(TCCR0,0);
SET_BIT(TCCR0,1);
CLR_BIT(TCCR0,2);
#elif CLK_SOURCE_MODE==PRESCALAR_OVER_256
CLR_BIT(TCCR0,0);
CLR_BIT(TCCR0,1);
SET_BIT(TCCR0,2);
#elif CLK_SOURCE_MODE==PRESCALAR_OVER_1024
SET_BIT(TCCR0,0);
CLR_BIT(TCCR0,1);
SET_BIT(TCCR0,2);
#elif CLK_SOURCE_MODE==PRESCALAR_OVER_FALLING_EDGE
CLR_BIT(TCCR0,0);
SET_BIT(TCCR0,1);
SET_BIT(TCCR0,2);
#elif CLK_SOURCE_MODE==PRESCALAR_OVER_RISING_EDGE
SET_BIT(TCCR0,0);
SET_BIT(TCCR0,1);
SET_BIT(TCCR0,2);
#endif

}
void timer_setpreload(u8 copy_u8preload){

TCCR0=copy_u8preload;

}
void timer_setctc(u8 copu_u8ocr){
OCR0=copu_u8ocr;

}
void timer_overflow_callback (void (*ptr_overflowapp)(void)){
	if(ptr_overflowapp!=NULL){
	if(glob_overflowisr_ptr==NULL)
	{
		glob_overflowisr_ptr=ptr_overflowapp;
	}
	}

}
void timer_CTC_callback (void (*ptr_ctcapp)(void)){
	if(ptr_ctcapp!=NULL){
	if(glob_ctcisr_ptr==NULL)
	{
		glob_ctcisr_ptr=ptr_ctcapp;
	}
	}


}
//ctc isr
void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	if(glob_ctcisr_ptr!=NULL)
	{
		glob_ctcisr_ptr();
	}
}

//overflow isr
void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{if(glob_overflowisr_ptr!=NULL)
{
	glob_overflowisr_ptr();
}

}

