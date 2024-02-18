/*

 * ADC_Private.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Nour
 */
#include"STD_TYPES_H_.h"
#include"BITMATH.h"
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define ADCH_REG		*((volatile u8*)0X25)
#define ADCL_REG		*((volatile u8*)0X24)
#define ADC_DATA_REG 	*((volatile u16*)0X24)

typedef struct
{
	u8 MUX: 5 ;
	u8 ADLAR:1;
	u8 REF:2;

}ADMUX;
#define ADMUX_REG ((volatile ADMUX*)0X27)

/***************************************/
typedef struct
{
	u8 ADPS:3;
	u8 ADIE:1;
	u8 ADIF:1;
	u8 ADATE:1;
	u8 ADSC:1;
	u8 ADEN:1; // ADC ENABLE

}ADCSRA;
#define ADCSRA_REG ((volatile ADCSRA*)0X26)

/***************************************/
typedef struct
{
	u8 :5;
	u8 ADTS:3;
}SFIOR;
#define SFIOR_REG ((volatile SFIOR*)0X50)






#endif /* ADC_PRIVATE_H_ */
