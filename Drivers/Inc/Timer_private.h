/*
 * Timer_private.h

 *
 *  Created on: Oct 27, 2023
 *      Author: Nour
 */
#include"DIO_interface.h"
#include"STD_TYPES_H_.h"
#include"BITMATH.h"

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


#define TCNT0_REG   *((volatile u8*)0x52)
#define OCR0_REG    *((volatile u8*)0x5C)




typedef struct
{
	u8 CS:    3;   //CLOCK SELECT
	u8 WGM01: 1;
	u8 COM:   2;
	u8 WGM00: 1;
	u8 FOC0:  1;

}TCCR0;
#define TCCR0_REG   ((volatile TCCR0*)0x53)




typedef struct
{
	u8 TOIE0:1;
	u8 OCIE0:1;

}TIMSK;
#define TIMSK_REG   ((volatile TIMSK*)0x59)

typedef struct
{
	u8 TOV0:1;
	u8 OCF0:1;
}TIFR;
#define TIFR_REG    ((volatile TIFR*)0x58)




#endif /* TIMER_PRIVATE_H_ */
