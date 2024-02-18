/*

 * LCD.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Nour
 */

#include "LCD_Config.h"

#ifndef LCD_H_
#define LCD_H_


void LCD_Init(void);
void lcd_write_CMD( u8 cmd);
void lcd_wirte_data(u8 data);

void LCD_Clear_Display(void);
void LCD_Send_String(u8 *ptrString);
void LCD_GOTOPOSITON(u8 col , u8 row);
void LCD_display_number(s32 Copy_s32Number);


#endif /* LCD_H_ */
