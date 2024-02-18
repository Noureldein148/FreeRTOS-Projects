/*
* Ext_INT.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Nour
 */
#include"Ext_INT.h"
#include "STD_TYPES_H_.h"
#include"BITMATH.h"
#include"DIO_interface.h"

#include "Global_INT.h"
#include"Timer.h"

static void (*po)(void);
static void (*GPTF[3])(void);

void Ext_Int_Init(u8 ext_int_num , u8 ext_int_mode)
{
	switch(ext_int_num)
	{
		case Ext_INT0:
		{
			SetBit(GICR_REG, GICR_INT0); // enabling INT0
			switch(ext_int_mode)
			{
				case Falling_Edge:
				{
					ClearBit(MCUCR_REG,MCUCR_ISC00);
					SetBit(MCUCR_REG , MCUCR_ISC01);
					break;
				}
				case Rising_Edge:
				{
					SetBit(MCUCR_REG , MCUCR_ISC00);
					SetBit(MCUCR_REG , MCUCR_ISC01);
					break;
				}
				default:
					break;
			}
			break;
		}
		case Ext_INT1:
		{
			SetBit(GICR_REG, GICR_INT1); // enabling INT1
			switch(ext_int_mode)
			{
				case Falling_Edge:
				{
					ClearBit(MCUCR_REG , MCUCR_ISC10);
					SetBit(MCUCR_REG , MCUCR_ISC11);
					break;
				}
				case Rising_Edge:
				{
					SetBit(MCUCR_REG , MCUCR_ISC10);
					SetBit(MCUCR_REG , MCUCR_ISC11);
					break;
				}
				default:
					break;
			}
				break;
		}
		case Ext_INT2:
		{
			SetBit(GICR_REG, GICR_INT2); // enabling INT2
			switch(ext_int_mode)
			{
				case Falling_Edge:
				{
					ClearBit(MCUCSR_REG,MCUSRR_ISC2);
					break;
				}
				case Rising_Edge:
				{
					SetBit(MCUCSR_REG,MCUSRR_ISC2);
					break;
				}
				default:
					break;
			}
				break;
		}
		default:
		break;
	}
}

void callback_Ext_INT0(void(*PTF)(void))
{
	GPTF[0] = PTF;
}
void callback_Ext_INT1(void(*PTF)(void))
{
	GPTF[1] = PTF;
}
void callback_Ext_INT2(void(*PTF)(void))
{
	GPTF[2] = PTF;
}
void __vector_1(void)
{
	GPTF[0]();
}
void __vector_2(void)
{
	GPTF[1]();
}
void __vector_3(void)
{
	GPTF[2]();
}










