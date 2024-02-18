/*

 * Timer_program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Nour
 */
#include"Timer.h"
#include"LCD.h"
static void (*gptr)(void) ;
static u16* timer0_locdata;


void Timer0_Init(void)
{
#if 	TIMER_0_MODE == NORMAL_MODE
		TCCR0_REG->WGM00 = 0b0;
		TCCR0_REG->WGM01 = 0b0;
		TIMSK_REG->TOIE0 =0b1;

#elif	TIMER_0_MODE == CTC_MODE
		TCCR0_REG->WGM00 = 0b0;
		TCCR0_REG->WGM01 = 0b1;
		// e7tmal ab2a nasy bit fel TIMSK wzyha t7t bs nt2kd

#elif	TIMER_0_MODE == PPWM_MODE
		TCCR0_REG->WGM00 = 0b1;
		TCCR0_REG->WGM01 = 0b0;
		TCCR0_REG->COM =   0b10; //Clear on compare match

#elif	TIMER_0_MODE == FPWM_MODE
		TCCR0_REG->WGM00 = 0b1;
		TCCR0_REG->WGM01 = 0b1;
		TCCR0_REG->COM= 0b10;


#endif


}
void Timer0_Stop(void)
{
	TCCR0_REG->CS = TIMER0_NO_CLK;

}

void Timer0_Start(void)
{
	// just give it a clk
	TCCR0_REG->CS = TIMER0_PRESCALAR;
}
void Timer0_Preload(u8 preload_val)
{
	TCNT0_REG = preload_val;
}
u8 Timer0_Val(void)
{
	return TCNT0_REG;
}

//void TIMER0_VoidSetPWMCompareMatch(u8 copy_u8Val )
//{
//	u8 Torq =0 ;
//	if(copy_u8Val <= 100)
//	{
//		Torq = (u8)((u32)(255 * copy_u8Val) / 100);  //u32 deh 3ashan lma tdrb fe 100 ht3dy el u8
//		OCR0_REG = Torq;
//	}
//	else
//	{
//		//return out of range error
//	}
//}
void TIMER0_SetPWMCompareMatch(u8 copy_u8Val )
{
	if(copy_u8Val >100)
	{
		copy_u8Val =100;
	}
	if(copy_u8Val<0)
	{
		copy_u8Val =0;
	}
	u8 pwm = (u32)copy_u8Val * 256;
	pwm = (u8)pwm/100 ;
	OCR0_REG =copy_u8Val;
}

void Callback_Timer0_OVF(void (*ptf)(void))
{
	if(ptf != NULL)
	{
			gptr = ptf;
	}
}
void __vector_11(void)
{
	gptr();

}



