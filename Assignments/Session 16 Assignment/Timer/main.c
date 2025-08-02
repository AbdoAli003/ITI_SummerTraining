#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"

#include "MCAL/DIO/DIO_interface.h"

#include "MCAL/TIMER/TIMER_interface.h"

#include "MCAL/GPI/GPI_Interface.h"

#include "HAL/KEYPAD/KEYPAD_interface.h"

#include "HAL/LCD/LCD_interface.h"

#include <string.h>


extern u8 TIMER_u8OneSec;

int main()
{
	GPI_voidEnable();
	TIMER_voidInit();
	KPD_voidInit();
	LCD_voidInit();
	TIMER_voidEnableInterrupt();
	u32 TotalSec = 0;
	u8 timeStr[6] = "00:00";
	u8 idx = 0;
	u8 Copy_pu8ReturnedKey;
	u8 right = 0, left = 0;
	while (1) {
			strcpy(timeStr,"00:00");
			idx = 0;
			TotalSec = 0;
			right = 0;
			left = 0;
			LCD_voidSendInstruction(CLEAR_SCREEN);
			LCD_voidWriteString("00:00");
			LCD_SetPos(0, 1);
			LCD_voidWriteString("+Left-Right=End"); // press + to move cursor left, - right and = to end
			LCD_SetPos(0, 0);
			LCD_voidSendInstruction(CURSOR_BLINK);
			while (1) {
			KPD_u8GetKeyState(&Copy_pu8ReturnedKey, 0);
			if (Copy_pu8ReturnedKey != KPD_u8_KEY_NOT_PRESSED)
			{
				if (Copy_pu8ReturnedKey == '+')
				{
					if (idx == 1) idx = 3;
					else if (idx < 4) idx++;
					LCD_SetPos(idx, 0);
				}
				if (Copy_pu8ReturnedKey == '-')
				{
					if (idx > 0)
					{
						if (idx == 3)
							idx = 1;
						else
							idx--;
						LCD_SetPos(idx, 0);
					}
				}
				if (Copy_pu8ReturnedKey == '=') break;
				if (Copy_pu8ReturnedKey < '0' || Copy_pu8ReturnedKey > '9') continue;
				if ((idx == 0 || idx == 3) && Copy_pu8ReturnedKey > '5') continue;
				if (idx > 4) continue;

				LCD_voidWriteChar(Copy_pu8ReturnedKey);
				timeStr[idx] = Copy_pu8ReturnedKey;
				if (idx <= 4)
				{
					idx++;
					if (idx == 2) idx++;
					LCD_SetPos(idx, 0);
				}
			}
			}
			LCD_voidSendInstruction(CLEAR_SCREEN);
			LCD_voidSendInstruction(CURSOR_OFF);
			TotalSec = (timeStr[0] - '0') * 10 * 60 + (timeStr[1] - '0') * 60
						+ (timeStr[3] - '0') * 10 + (timeStr[4] - '0');
			while (TotalSec > 0)
			{
				if (TIMER_u8OneSec)
				{
					TIMER_u8OneSec = 0;
					TotalSec--;
					LCD_SetPos(0, 0);
					u8 min = TotalSec / 60;
					u8 sec = TotalSec % 60;
					LCD_voidWriteChar((min / 10) + '0');
					LCD_voidWriteChar((min % 10) + '0');
					LCD_voidWriteChar(':');
					LCD_voidWriteChar((sec / 10) + '0');
					LCD_voidWriteChar((sec % 10) + '0');
				}
			}

	}

	return 0;
}

