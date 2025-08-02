#include "DIO_DRIVER.h"
u8 DIO_u8SetPinDirection(u8 Copy_PortID, u8 Copy_PinID, u8 Copy_PinDirection)
{
	if (Copy_PinID > 7 || Copy_PinDirection > 1 || Copy_PinDirection < 0)
		return 0;
	switch (Copy_PortID)
	{
	case PORTA:
		DIO_u8_PORTA_REG = Copy_PinDirection ? set(DIO_u8_PORTA_REG,Copy_PinID) : rst(DIO_u8_PORTA_REG,Copy_PinID);
		break;
	case PORTB:
		DIO_u8_PORTB_REG = Copy_PinDirection ? set(DIO_u8_PORTB_REG,Copy_PinID) : rst(DIO_u8_PORTB_REG,Copy_PinID);
		break;
	case PORTC:
		DIO_u8_PORTC_REG = Copy_PinDirection ? set(DIO_u8_PORTC_REG,Copy_PinID) : rst(DIO_u8_PORTC_REG,Copy_PinID);
		break;
	case DDRA:
		DIO_u8_DDRA_REG = Copy_PinDirection ? set(DIO_u8_DDRA_REG,Copy_PinID) : rst(DIO_u8_DDRA_REG,Copy_PinID);
		break;
	default:
		return 0;
	}
	return 1;
}
u8 DIO_u8SetPinValue(u8 Copy_PortID, u8 Copy_PinID, u8 Copy_PinValue)
{
	if (Copy_PinID > 7 || Copy_PinValue > 1 || Copy_PinValue < 0)
		return 0;
	switch (Copy_PortID)
	{
	case PORTA:
		DIO_u8_PORTA_REG = Copy_PinValue ? set(DIO_u8_PORTA_REG,Copy_PinID) : rst(DIO_u8_PORTA_REG,Copy_PinID);
		break;
	case PORTB:
		DIO_u8_PORTB_REG = Copy_PinValue ? set(DIO_u8_PORTB_REG,Copy_PinID) : rst(DIO_u8_PORTB_REG,Copy_PinID);
		break;
	case PORTC:
		DIO_u8_PORTC_REG = Copy_PinValue ? set(DIO_u8_PORTC_REG,Copy_PinID) : rst(DIO_u8_PORTC_REG,Copy_PinID);
		break;
	case DDRA:
		DIO_u8_DDRA_REG = Copy_PinValue ? set(DIO_u8_DDRA_REG,Copy_PinID) : rst(DIO_u8_DDRA_REG,Copy_PinID);
		break;
	default:
		return 0;
	}
	return 1;
}

