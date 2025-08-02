#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "LIB/delay.h"

#include "MCAL/DIO/DIO_interface.h"

#include "HAL/LCD/LCD_interface.h"

#include "HAL/KEYPAD/KEYPAD_interface.h"

int main()
{
	DIO_voidInit();
	LCD_voidInit();
	KPD_voidInit();
	u8 Copy_pu8ReturnedKey;
	while (1)
	{
		KPD_u8GetKeyState(&Copy_pu8ReturnedKey);
		if (Copy_pu8ReturnedKey != KPD_u8_KEY_NOT_PRESSED)
		{
			LCD_voidSendInstruction(CLEAR_SCREAN);
			LCD_voidWriteChar(Copy_pu8ReturnedKey);
		}
	}
	return 0;
}
