#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"


void SPI_voidInit()
{
	switch (MODE)
	{
	case MASTER:
		SPI_voidMasterInit();
		break;
	case SLAVE:
		SPI_voidSlaveInit();
		break;
	default:
		break;
	}
}
u8 SPI_u8TransRecieve(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	while (!GET_BIT(SPSR,SPIF));
	return SPDR;
}
void SPI_voidMasterInit()
{
	// Master mode
	SET_BIT(SPCR,MSTR);
	// Prescaler
	CLR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPCR,SPI2X);
	// Enable
	SET_BIT(SPCR,SPE);

	CLR_BIT(SPCR,DORD);

	CLR_BIT(SPCR,CPHA);
	CLR_BIT(SPCR,CPOL);
}
void SPI_voidSlaveInit()
{
	// Slave mode
	CLR_BIT(SPCR,MSTR);
	// Prescaler
	/*CLR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPCR,SPI2X);
	*/
	// Enable
	SET_BIT(SPCR,SPE);

	CLR_BIT(SPCR,DORD);

	CLR_BIT(SPCR,CPHA);
	CLR_BIT(SPCR,CPOL);
}
