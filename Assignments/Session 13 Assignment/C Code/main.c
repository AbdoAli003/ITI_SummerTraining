/*
Made By:
 =========== Abdulrahman Ali ===========
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"
#include "LIB/delay.h"

#include "MCAL/DIO/DIO_interface.h"

#include "HAL/LCD/LCD_interface.h"

#include "HAL/KEYPAD/KEYPAD_interface.h"

#include "HAL/DC_MOTOR/DC_MOTOR_interface.h"

#include "HAL/STEPPER/STEPPER_interface.h"



int main()
{
	DIO_voidInit();
	LCD_voidInit();
	KPD_voidInit();
	DC_MOTOR_voidInit();
	STEPPER_voidInit();
	u8 Copy_pu8ReturnedKey;
	u32 steps = 0;
	u8 direction = 0;
	u8 count = 0;
	u8 flag = 0;
	u8 menuDisplayed = 0;
	while (1)
	{
		if (menuDisplayed == 0)
		{
			LCD_voidSendInstruction(CLEAR_SCREEN);
			LCD_voidWriteString("1 DC MOTOR");
			LCD_SetPos(0, 1);
			LCD_voidWriteString("2 STEPPER");
			LCD_SetPos(0, 0);
			menuDisplayed = 1;
		}
		KPD_u8GetKeyState(&Copy_pu8ReturnedKey,0);
		if (Copy_pu8ReturnedKey != KPD_u8_KEY_NOT_PRESSED)
		{
			if (Copy_pu8ReturnedKey == DC_MOTOR)
			{

				while (1) {
					flag = 0;
				LCD_voidSendInstruction(CLEAR_SCREEN);
				LCD_voidWriteString("1 ON");
				LCD_SetPos(0, 1);
				LCD_voidWriteString("2 OFF");
				LCD_SetPos(0, 0);
				while (1)
				{
					KPD_u8GetKeyState(&Copy_pu8ReturnedKey, 0);
					if (Copy_pu8ReturnedKey != KPD_u8_KEY_NOT_PRESSED)
					{
						if (Copy_pu8ReturnedKey == '1')
							{DC_MOTOR_on(); flag = 1; break;}
						else if (Copy_pu8ReturnedKey == '2')
							{DC_MOTOR_off(); flag = 1; break;}
					}

				}
				if (flag) break;
				}
			}
			else if (Copy_pu8ReturnedKey == STEPPER)
					{
						while (1) {
							steps = 0;
							count = 0;
						LCD_voidSendInstruction(CLEAR_SCREEN);
						LCD_voidWriteString("Steps:");
						LCD_SetPos(0, 1);
						LCD_voidWriteString("End with *");
						LCD_SetPos(0, 0);
						while (1)
						{
							KPD_u8GetKeyState(&Copy_pu8ReturnedKey, 0);
							if (Copy_pu8ReturnedKey != KPD_u8_KEY_NOT_PRESSED)
							{
								if (count == 0)
									LCD_voidSendInstruction(CLEAR_SCREEN);
								if (Copy_pu8ReturnedKey != '*'){
									steps = steps * 10 + (Copy_pu8ReturnedKey - (u8)'0');
								LCD_voidWriteChar(Copy_pu8ReturnedKey);}
								else break;
								count++;
							}
						}
						if (Copy_pu8ReturnedKey == '*' && count == 0) break;
						LCD_voidSendInstruction(CLEAR_SCREEN);
						LCD_voidWriteString("Direction:");
						LCD_SetPos(0, 1);
						LCD_voidWriteString("1:C 2:CC");
						LCD_SetPos(0, 0);
						while (1) {
						KPD_u8GetKeyState(&Copy_pu8ReturnedKey, 0);
						if (Copy_pu8ReturnedKey != KPD_u8_KEY_NOT_PRESSED)
						{
							LCD_voidSendInstruction(CLEAR_SCREEN);
							LCD_voidWriteChar(Copy_pu8ReturnedKey);
							direction = (Copy_pu8ReturnedKey == '1') ? CLOCKWISE : COUNTER_CLOCKWISE;
							break;
						}
						}

						STEPPER_u8MoveSteps(direction, steps);
						LCD_voidSendInstruction(CLEAR_SCREEN);
						LCD_voidWriteString("Moving..");
					}
		}
		menuDisplayed = 0;
	}
	}
	return 0;
}
