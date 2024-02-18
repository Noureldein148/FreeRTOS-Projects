/*
 * ADC.h
 *
 *  Created on: Oct 24, 2023
 *      Author: admin
 */
#include"ADC_Config.h"
#ifndef ADC_H_
#define ADC_H_

void ADC_Init(void);
void ADC_Channel_Select(void);
void ADC_Start_Conv(void);
void ADC_ReadData_AutoTrig(void );
//void ADC_ReadData(u16*x);
u16 ADC_ReadData(u16 ADC_Channel);
void ADC_AutoTrig(void);
void callback_ADC(u16 *addrs_frm_main , void(*ptf)(void));
/*ISR*/
void __vector_16(void) __attribute__((signal));
u16 map(u32 x1 , u32 x2 , u32 y1,u32 y2,u16);
u16 ADC_mapping(u16 adc_value, u16 adc_lower_range, u16 adc_upper_range, u16 new_lower_range, u16 new_upper_range);
#endif /* ADC_H_ */
