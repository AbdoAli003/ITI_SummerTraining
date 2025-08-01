#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"

void UART_voidInit()
{
	// 8 bit data mode
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);
	// 9600
	UBRRL = 51;
	// enable trans/recv
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	// async
}
void UART_voidSendData(u8 Copy_u8Data)
{
	while (!GET_BIT(UCSRA,UDRE));
		UDR = Copy_u8Data;
}
u8 UART_u8Recieve()
{
	while (!GET_BIT(UCSRA,RXC));
		return UDR;
}
void UART_voidSendString(u8 Copy_u8PrintedData[])
{
	u8* ptr = Copy_u8PrintedData;
	while (*ptr != '\0')
	{
		UART_voidSendData(*ptr);
		ptr++;
	}
}
