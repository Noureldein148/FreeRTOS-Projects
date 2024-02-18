/*

 * Global_INT.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Nour
 */
#include"Global_INT.h"
void Global_int_en(void)
{
	SetBit(SREG_REG ,SREG_I);
}
void Global_int_dis(void)
{
	ClearBit(SREG_REG ,SREG_I);
}

