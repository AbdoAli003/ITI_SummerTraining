#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"

#include "MCAL/DIO/DIO_interface.h"

#include "HAL/LCD/LCD_interface.h"



#include "LIB/delay.h"

int main()
{

	DIO_voidInit();
	LCD_voidInit();
	while (1)
	{

		for (u8 i = 0; i <= 12; i++)
		{
			LCD_SetPos(i,0);
			LCD_voidWriteString("ABDO");
			delay_ms(80);
			LCD_voidSendInstruction(CLEAR_SCREAN);
			delay_ms(80);
		}
		for (u8 i = 11; i >= 1; i--)
			{
				LCD_SetPos(i,0);
				LCD_voidWriteString("ABDO");
				delay_ms(80);
				LCD_voidSendInstruction(CLEAR_SCREAN);
				delay_ms(80);
			}
	}


	return 0;
}






