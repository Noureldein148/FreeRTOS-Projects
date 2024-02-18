/*

 * ADC_Config.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Nour
 */
#include"ADC_Private.h"
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


#define RIGHT_ADJUST 0b0
#define LEFT_ADJUST  0b1

#define ADC_TYPE_DATA 	RIGHT_ADJUST
/***************************************************/
#define AREF_Internal_Vref_turned_off 0b00
#define AVCC 						  0b01
#define RESERVED 					  0b10
#define Internal_2_56_Voltage         0b11

#define ADC_V_REF 		AVCC
/****************************************************/
#define ADC_PRESCALAR_div_1   0b000 // mktoba 2 fel datasheet bs 8albn 8alta
#define ADC_PRESCALAR_div_2   0b001
#define ADC_PRESCALAR_div_4   0b010
#define ADC_PRESCALAR_div_8   0b011
#define ADC_PRESCALAR_div_16  0b100
#define ADC_PRESCALAR_div_32  0b101
#define ADC_PRESCALAR_div_64  0b110
#define ADC_PRESCALAR_div_128 0b111

#define ADC_PRESCALAR   ADC_PRESCALAR_div_1
/***************************************************/

#define ADC_EN_STATUS	0b1
#define ADC_INT_EN_STATUS 0b1
/***************************************************/
typedef enum
{
	ADC_CH0 ,
	ADC_CH1 ,
	ADC_CH2 ,
	ADC_CH3 ,
	ADC_CH4 ,
	ADC_CH5 ,
	ADC_CH6 ,
	ADC_CH7
} ADC_Channel;


#endif /* ADC_CONFIG_H_ */
