#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"

#include <avr/delay.h>

#include "MCAL/DIO/DIO_interface.h"

#include "MCAL/TIMER/TIMER_interface.h"

#include "MCAL/GPI/GPI_Interface.h"

#include "MCAL/ADC/ADC_interface.h"

#include "HAL/KEYPAD/KEYPAD_interface.h"

#include "HAL/LCD/LCD_interface.h"




int main()
{
	DIO_voidInit();
	ADC_voidInit();
	TIMER_voidFPWM_Init();
	u16 Reading;
	while (1)
	{
		ADC_u16ReadSync(ADC0, &Reading);
		f32 volt = (f32)Reading * (5.0 / 1024.0);
		u8 DutyCycle = (u8)(volt * 25.0) + 125;
		TIMER_voidSetDutyCycle(DutyCycle);
		_delay_ms(100);
	}


	return 0;
}


