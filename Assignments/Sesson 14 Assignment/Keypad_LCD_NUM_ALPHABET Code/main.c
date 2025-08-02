#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "LIB/delay.h"

#include "MCAL/DIO/DIO_interface.h"

#include "HAL/LCD/LCD_interface.h"

#include "HAL/KEYPAD/KEYPAD_interface.h"

#include "MCAL/GPI/GPI_interface.h"

#include "MCAL/EXTI/EXTI_interface.h"

void INT_CallBack(void);
u8 ALPHA = 0; // flag to swap between numbers and alphabets
int main()
{
	DIO_voidInit();
	LCD_voidInit();
	KPD_voidInit();
	u8 Copy_pu8ReturnedKey;

	DIO_u8SetPinDirection(DIO_u8_PORTD, DIO_u8_PIN3, DIO_u8_INPUT);
	DIO_u8SetPinValue(DIO_u8_PORTD, DIO_u8_PIN3, DIO_u8_HIGH);

	EXTI_voidEXTIEnable(1, 2); // INT1 FALLING EDGE
	GPI_voidEnable();
	EXTI_voidSetCallBack(INT_CallBack, 1);
	while (1)
	{
		KPD_u8GetKeyState(&Copy_pu8ReturnedKey,ALPHA);
		if (Copy_pu8ReturnedKey != KPD_u8_KEY_NOT_PRESSED)
		{
			//LCD_voidSendInstruction(0b00000001); // cls
			LCD_voidWriteChar(Copy_pu8ReturnedKey);
		}
	}


	return 0;
}
void INT_CallBack(void)
{
	//delay_ms(50);
	ALPHA = !ALPHA;
}

