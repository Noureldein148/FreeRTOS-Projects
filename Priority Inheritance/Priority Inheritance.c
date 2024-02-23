/*****************************************************************************
 *==================******************************************================*
 *==================**   Author: Nour El Dein Hany Sayed    **================*
 *==================**                                      **================*
 *==================******************************************================*
 /*****************************************************************************/
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

/* Configuration */
#define BINARY 0
#define MUTEX  1
#define SEMAPHORE_TYPE  BINARY

/* Prototypes 	*/
void system_Init(void);
void T_L(void *pvParam);
void T_M(void *pvParam);
void T_H(void *pvParam);

xSemaphoreHandle MutexRes = NULL;
TaskHandle_t Handle;

/*	Note	*/
//xTaskCreate(pvTaskCode , pc Name , StackSize(in_word_size) , pvParam ,Priority , Refrecnce_on_TCB);

int main(void)
{
	system_Init();
	/*Create OS objects */
/***************************************************************
**********Choose between Mutex and Binary Semaphore ************
/**************************************************************/

#if SEMAPHORE_TYPE == MUTEX
	MutexRes =xSemaphoreCreateMutex();
#endif

#if SEMAPHORE_TYPE == BINARY
	MutexRes =xSemaphoreCreateBinary();
#endif

	xSemaphoreGive(MutexRes);

	if(MutexRes == NULL){
		UART_VoidSendString("Semaphore Not Created \r\n");
	}
	/*	Creating Tasks	*/
	xTaskCreate(T_L ,"T_L", 200, NULL, 1, &Handle);

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

void T_L(void *pvParam)
{
	u8 Pri = 0 ;
	LCD_GOTOPOSITON(0,0);
	while(1)
	{
		LED_BLU_ON();
		_delay_ms(1000);
		LED_BLU_OFF();

		// Initial Priority
		Pri = uxTaskPriorityGet(NULL);
		LCD_display_number(Pri);

		xSemaphoreTake(MutexRes , portMAX_DELAY);
		xTaskCreate(T_H,"T_H" , 200 ,NULL ,3 ,NULL);

		// Priority After Semaphore Take (Inheritance )
		Pri = uxTaskPriorityGet(NULL);
		LCD_display_number(Pri);

		xTaskCreate(T_M,"T_M" , 200 ,NULL ,2,NULL);
		xSemaphoreGive(MutexRes);
	}
}

void T_M(void *pvParam)
{

	while(1)
	{
		LED_GRN_ON();
		_delay_ms(9000);
		UART_VoidSendString("H\r\n");
		LED_GRN_OFF();
		UART_VoidSendString("Enn of T_M\r\n");
		vTaskDelay(9000);
	}
}
void T_H(void *pvParam)
{
	u8 Pri = 0;
	while(1)
	{
		LED_RED_ON();
		_delay_ms(2000);
		LED_RED_OFF();
		xSemaphoreTake(MutexRes , portMAX_DELAY);

		// Priority After Semaphore Give (De-Inheritance )
		Pri = uxTaskPriorityGet(Handle);
		LCD_display_number(Pri);

		UART_VoidSendString("END of Prog\r\n");
		while(1);
	}
}
