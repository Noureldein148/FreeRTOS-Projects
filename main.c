/*****************************************************************************
 *==================******************************************================*
 *==================**   Author: Nour El Dein Hany Sayed    **================*
 *==================**                                      **================*
 *==================******************************************================*
 /*****************************************************************************/
 
 /*Video : https://drive.google.com/file/d/1lRXmxYrB3ounrJmlzd3o1RfitnIwTw8i/view?usp=sharing */
// Driverts Includes
#include"DIO_interface.h"
#include"DIO_private.h"
#include"BITMATH.h"
#include"LED.h"
#include"UART_interface.h"
#include"LCD.h"
#include"ADC.h"
#include <util/delay.h>
#define F_CPU 8000000UL

// FreeRTOS Inlcudes
#include"FreeRTOS.h"
#include"task.h"
#include"queue.h"
#include "semphr.h"
#include "event_groups.h"

#define isBtnPressed  GetBit(PIND ,7)

/* Prototypes 	*/
void system_Init(void);
void T_LED(void *pvParam);
void T_ADC(void *pvParam);

xSemaphoreHandle bsBtnSem = NULL;  // bs : binary semaphore
u16 Temp = 0;

/*	Note	*/
//xTaskCreate(pvTaskCode , pc Name , StackSize(in_word_size) , pvParam ,Priority , Refrecnce_on_TCB);

int main(void)
{
	system_Init();
	/*Create OS objects */
	bsBtnSem =xSemaphoreCreateBinary();
	if(bsBtnSem == NULL){
		UART_VoidSendString("Semaphore Not Created \r\n");
	}

	/*	Creating Tasks	*/
	xTaskCreate(T_LED ,"T_LED", 100, NULL, 1, NULL);
	xTaskCreate(T_ADC ,"T_ADC", 250, NULL, 2, NULL);

	/*	Start OS	*/
	vTaskStartScheduler();

	/*	Unreachable Code	*/
	while(1)
	{

	}
	return 0 ;
}

void system_Init(void)
{
	ADC_Init();
	DIO_SetPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_LOW); //LM35
	LCD_Init();
	LEDS_ALL_Init();
	UART_Init();
	UART_VoidSendString("System Init...\r\n");
	DIO_SetPinDirection(DIO_PORTD , DIO_PIN7 , DIO_PIN_LOW);//Button
}

void T_LED(void *pvParam)
{
	while(1)
	{
		if(xSemaphoreTake(bsBtnSem , portMAX_DELAY)) {//timeout
			LEDS_ALL_TOGGLE();
		}
	}
}

void T_ADC(void *pvParam)
{
	u8 var = 0;
	while(1)
	{
		taskENTER_CRITICAL();
		Temp = ADC_ReadData(ADC_CH1);
		taskEXIT_CRITICAL();
		Temp = ADC_mapping(Temp, 0, 1023, 0, 500);

		LCD_GOTOPOSITON(0, 0);
		LCD_display_number((s32) Temp);
		if(Temp>=100)
		{
			var=1 ;
			xSemaphoreGive(bsBtnSem);
			LCD_GOTOPOSITON(1,0);
			LCD_Send_String("WARNING");
		}
		if(var == 1 && Temp <100){
			LCD_Clear_Display();
			LEDS_ALL_OFF();
			var = 0;
		}
		vTaskDelay(200);
	}
}
