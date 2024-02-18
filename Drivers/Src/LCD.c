/*


 * LCD.c
 *
 *  Created on: Oct 21, 2023
 *      Author:Nour
 *      Layer : HAL
 *      SWC   : LCD
 */
#include "LCD.h"
#include"DIO_interface.h"
#include <avr/delay.h>


void LCD_Init(void)
{
	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN , DIO_PIN_HIGH);
	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN , DIO_PIN_HIGH);

	DIO_SetPinDirection(LCD_DATA_PORT , LCD_DATA_PIN_4 , DIO_PIN_HIGH);
	DIO_SetPinDirection(LCD_DATA_PORT , LCD_DATA_PIN_5 , DIO_PIN_HIGH);
	DIO_SetPinDirection(LCD_DATA_PORT , LCD_DATA_PIN_6 , DIO_PIN_HIGH);
	DIO_SetPinDirection(LCD_DATA_PORT , LCD_DATA_PIN_7 , DIO_PIN_HIGH);

	_delay_ms(100);
	lcd_Write_CMD(0x33);
	lcd_Write_CMD(0x32);
	lcd_Write_CMD(0x28);

	lcd_Write_CMD(0x0c);
	lcd_Write_CMD(0x02);
	lcd_Write_CMD(0x01);
	lcd_Write_CMD(0x06);



}

void lcd_Write_CMD( u8 cmd)
{
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_PIN_LOW);
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_RS_PIN , DIO_PIN_LOW);

	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_4 , GetBit(cmd , 4));
	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_5 , GetBit(cmd , 5));
	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_6 , GetBit(cmd , 6));
	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_7 , GetBit(cmd , 7));

	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_PIN_LOW);

	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_4 , GetBit(cmd , 0));
	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_5 , GetBit(cmd , 1));
	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_6 , GetBit(cmd , 2));
	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_7 , GetBit(cmd , 3));

	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_PIN_LOW);

	_delay_ms(5);
}

void lcd_wirte_data(u8 data)
{
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_PIN_LOW);
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_RS_PIN , DIO_PIN_HIGH);

	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_4 , GetBit(data , 4));
	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_5 , GetBit(data , 5));
	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_6 , GetBit(data , 6));
	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_7 , GetBit(data , 7));

	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_PIN_LOW);

	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_4 , GetBit(data , 0));
	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_5 , GetBit(data , 1));
	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_6 , GetBit(data , 2));
	DIO_SetPinValue(LCD_DATA_PORT , LCD_DATA_PIN_7 , GetBit(data , 3));

	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(LCD_CTRL_PORT , LCD_EN_PIN , DIO_PIN_LOW);

	_delay_ms(5);
}

void LCD_Clear_Display(void)
{
	lcd_Write_CMD(0x01);
}

void LCD_Send_String(u8 *ptrString)
{
	while(*ptrString != 0 )
	{
		lcd_wirte_data(*ptrString);
		ptrString++;
	}
}

void LCD_GOTOPOSITON(u8 row , u8 col)
{
	u8 arr[4] = {0X80 , 0XC0,0X94 , 0XD4};
	lcd_Write_CMD( arr[row] + col  );
}
void LCD_display_number(s32 Copy_s32Number)
{
	if(Copy_s32Number == 0)
	{
		lcd_wirte_data('0');
	}
	else if(Copy_s32Number > 0  )
	{
		s8 i=0;
	    u8 Copy_u8Remander = 0;
	    u8 arr[10] = {0};
	    while(Copy_s32Number != 0)
	    {
	    	Copy_u8Remander = Copy_s32Number % 10;
	    	arr[i] = Copy_u8Remander;
	    	i++;
	    	Copy_s32Number /= 10;
	    }
	    i--;
	    while(i >= 0)
	    {
	    	lcd_wirte_data(arr[i] + 48);
	    	i--;
	    }

	}
}

