#include "avr/io.h"
#include "avr/delay.h"
#include "DIO_DRIVER.h"

int main()
{
	DIO_u8SetPinDirection(DDRA, DIO_u8_PIN0, DIO_u8_OUTPUT);
	while (1)
	{
		DIO_u8SetPinValue(PORTA, DIO_u8_PIN0, DIO_u8_HIGH);
		_delay_ms(1000);
		DIO_u8SetPinValue(PORTA, DIO_u8_PIN0, DIO_u8_LOW);
		_delay_ms(1000);
	}
	return 0;
}



