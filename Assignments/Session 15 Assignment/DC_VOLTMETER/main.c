#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"
#include "LIB/delay.h"

#include <stdio.h>

#include "MCAL/DIO/DIO_interface.h"

#include "HAL/LCD/LCD_interface.h"

#include "MCAL/GPI/GPI_interface.h"

#include "MCAL/EXTI/EXTI_interface.h"

#include "MCAL/ADC/ADC_interface.h"
// dio init
// adc init
// get digital value
// voltage = digital * 5 / 1024
int main()
{
	DIO_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	f32 pos_volt, neg_volt, volt;
	u8 voltStr[16];
	u8 sign = '+';
	while (1) {
	pos_volt = ADC_f32Read(ADC0);
	neg_volt = ADC_f32Read(ADC5);
	volt = pos_volt - neg_volt;
	if (volt < 0)
	{
		sign = '-';
		volt = -volt;
	}
	u16 intPart = (u16)volt;
	u16 fracPart = (u16)((volt - intPart) * 1000);
	sprintf(voltStr, "%c%u.%03u", sign, intPart, fracPart);
	LCD_voidSendInstruction(0b00000001);
	LCD_voidWriteString(voltStr);
	delay_ms(100);
	}
	return 0;
}

