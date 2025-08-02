#include "avr/io.h"
#include "avr/delay.h"
#include "DIO_DRIVER.h"

int main()
{
	for (u8 i = DIO_u8_PIN0; i <= DIO_u8_PIN7; i++)
	DIO_u8SetPinDirection(DDRA, i, DIO_u8_OUTPUT);
	while (1)
	{
		DIO_u8SetPinValue(PORTA, DIO_u8_PIN0, DIO_u8_HIGH);
		_delay_ms(1000);
		DIO_u8SetPinValue(PORTA, DIO_u8_PIN0, DIO_u8_LOW);
		for (u8 i = DIO_u8_PIN1; i <= DIO_u8_PIN6; i++)
		{
			DIO_u8SetPinValue(PORTA, i, DIO_u8_HIGH);
			_delay_ms(1000);
			DIO_u8SetPinValue(PORTA, i, DIO_u8_LOW);
		}
		DIO_u8SetPinValue(PORTA, DIO_u8_PIN7, DIO_u8_HIGH);
		_delay_ms(1000);
		DIO_u8SetPinValue(PORTA, DIO_u8_PIN7, DIO_u8_LOW);
		for (u8 i = DIO_u8_PIN6; i >= DIO_u8_PIN1; i--)
		{
			DIO_u8SetPinValue(PORTA, i, DIO_u8_HIGH);
			_delay_ms(1000);
			DIO_u8SetPinValue(PORTA, i, DIO_u8_LOW);
		}
	}
	return 0;
}






