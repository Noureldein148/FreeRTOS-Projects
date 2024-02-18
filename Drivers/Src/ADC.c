/*

 * ADC.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Nour
 */

#include "DIO_interface.h"
#include"ADC.h"
#include "LCD.h"
#include <util/delay.h>

#define TIME_OUT  100000UL

static u16 *adc_po_data;
static void (*gp) (void);


void callback_ADC(u16 *addrs_frm_main , void(*ptf)(void))
{
	if(addrs_frm_main != NULL ){
		adc_po_data = addrs_frm_main;
	}
	if(ptf != NULL){
		gp = ptf;
	}
}
void __vector_16(void)
{
	*adc_po_data = ADC_DATA_REG;
	gp();
}


//void ADC_ChannelSelect(void)
//{
//
//	DIO_SetPinDirection(DIO_PORTA, DIO_PIN1,DIO_PIN_LOW); //LM35
//	ADMUX_REG->MUX = ADC_Channel;
//}
void ADC_Init(void)
{
	ADMUX_REG->ADLAR = ADC_TYPE_DATA;
	ADMUX_REG->REF = ADC_V_REF;
	ADCSRA_REG->ADPS =ADC_PRESCALAR;
	ADCSRA_REG->ADEN = ADC_EN_STATUS;
	ADCSRA_REG->ADIE = ADC_INT_EN_STATUS;

	//ADCSRA_REG->ADATE = 0b1; //Auto Trigger enabled
	//SFIOR_REG->ADTS = 0b010; // External Interrupt Request 0
	//SFIOR_REG->ADTS = 0b100; // Timer_0_OVF
}

void ADC_Start_Conv()
{
	ADCSRA_REG->ADSC = 0b1;
}

//void ADC_ReadData(u16* Data_Ref )
//{
//	//u16 Data_Ref=0;
//	ADCSRA_REG->ADSC = 0b1;	 //start conversion
//	while(ADCSRA_REG->ADIF == 0);
//	*Data_Ref = ADC_DATA_REG ;
//	ADCSRA_REG->ADIF = 0b1; //Clearing the flag by writing 1 (Hardware)
//}

u16 ADC_ReadData(u16 copy_u16_ADC_Channel  )
{
	if(copy_u16_ADC_Channel >=0  && copy_u16_ADC_Channel <=7){
		ADMUX_REG->MUX = ADC_CH1;
	}
	u16 Data_Ref;
	ADCSRA_REG->ADSC = 0b1;	 //start conversion

	while(ADCSRA_REG->ADIF == 0);
	Data_Ref = ADC_DATA_REG ;
	ADCSRA_REG->ADIF = 0b1; //Clearing the flag by writing 1 (Hardware)
	return Data_Ref;
}

//void ADC_ReadData_AutoTrig(void )
//{
//	adc_local_data = ADC_DATA_REG;
//	LCD_GOTOPOSITON(0,0);
//	LCD_display_number((s32)adc_local_data);
//	_delay_ms(1300);
//}

void ADC_AutoTrig(void)
{
	ADCSRA_REG->ADATE = 0b1; //Auto Trigger enabled
	//SFIOR_REG->ADTS = 0b0100; // timer 0 overflow

}



u16 map(u32 x1 , u32 x2 , u32 y1,u32 y2 ,u16 x)
{
	u32 numerator = ( (u32)x-x1*(y2 -y1) );
	numerator	  = ( (u32)numerator/(x2-x1)  );
	numerator	  = ( (u32)numerator+y1);
	return numerator;
}

u16 ADC_mapping(u16 adc_value, u16 adc_lower_range, u16 adc_upper_range, u16 new_lower_range, u16 new_upper_range)
{
	// Ensure the ADC value is within the specified range
	    if (adc_value < adc_lower_range)
	    {
	        adc_value = adc_lower_range;
	    }
	    else if (adc_value > adc_upper_range)
	    {
	        adc_value = adc_upper_range;
	    }

	    // Map the ADC value to the new range
	    u32  mapped_value = (u32)(adc_value - adc_lower_range) * (u32)(new_upper_range - new_lower_range);
	    mapped_value /= (u32)(adc_upper_range - adc_lower_range);
	    mapped_value += new_lower_range;

	    return (u16)mapped_value;
}


