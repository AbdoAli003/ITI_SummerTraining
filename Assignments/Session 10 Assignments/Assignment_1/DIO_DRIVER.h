#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_
#include "BITMATH.h"
#include "STD_TYPES.h"
#define DIO_u8_PORTA_REG *((volatile u8*)0x3B)
#define DIO_u8_PORTB_REG *((volatile u8*)0x38)
#define DIO_u8_PORTC_REG *((volatile u8*)0x35)
#define DIO_u8_DDRA_REG *((volatile u8*)0x3A)
#define DIO_u8_PIN0 0
#define DIO_u8_PIN1 1
#define DIO_u8_PIN2 2
#define DIO_u8_PIN3 3
#define DIO_u8_PIN4 4
#define DIO_u8_PIN5 5
#define DIO_u8_PIN6 6
#define DIO_u8_PIN7 7
#define DIO_u8_LOW 0
#define DIO_u8_HIGH 1
#define DIO_u8_INPUT 0
#define DIO_u8_OUTPUT 1
#define PORTA		0
#define PORTB 		1
#define PORTC 		2
#define DDRA		3

u8 DIO_u8SetPinDirection(u8 Copy_PortID, u8 Copy_PinID, u8 Copy_PinDirection);
u8 DIO_u8SetPinValue(u8 Copy_PortID, u8 Copy_PinID, u8 Copy_PinValue);

#endif /* DIO_DRIVER_H_ */
