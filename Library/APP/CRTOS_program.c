#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/TIMER/TIMER_interface.h"
#include "MCAL/TIMER/TIMER_private.h"

#include "MCAL/GPI/GPI_Interface.h"

#include "CRTOS_config.h"
#include "CRTOS_interface.h"
#include "CRTOS_private.h"

Task_t* Task[CRTOS_u8_MAX_TASK_NUM];

u32 OVF_count = 0;
void CRTOS_voidInit()
{
	for (u8 i = 0; i < CRTOS_u8_MAX_TASK_NUM; i++)
		Task[i] = CRTOS_u8_NULL;
	TIMER_voidInit();
	TIMER_voidEnableInterrupt();
	GPI_voidEnable();
	TIMER_u8SetCallBackNormal(CRTOS_voidOVFCount);
}

void CRTOS_voidCreateTask(Task_t* TaskPointer, u8 Copy_u8Priority)
{
	Task[Copy_u8Priority] = TaskPointer;
}
void CRTOS_voidScheduler(void)
{
	for (u8 i = 0; i < CRTOS_u8_MAX_TASK_NUM; i++)
	{
		if (Task[i] != CRTOS_u8_NULL)
		{
			if (Task[i]->state == CRTOS_u8_TASK_RUNNING)
			{
				if (Task[i]->first_delay == 0)
				{
					Task[i]->PtrFunc();
					Task[i]->first_delay = Task[i]->periodicity - 1;
				}
				else
				{
					Task[i]->first_delay--;
				}
			}
			else if (Task[i]->state == CRTOS_u8_TASK_DELETED)
			{
				Task[i]->state = CRTOS_u8_NULL;
			}
		}
	}
}
void CRTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	if (Task[Copy_u8Priority] != CRTOS_u8_NULL)
	{
		Task[Copy_u8Priority]->state = CRTOS_u8_TASK_PAUSED;
	}
}
void CRTOS_voidStartTask(u8 Copy_u8Priority)
{
	if (Task[Copy_u8Priority] != CRTOS_u8_NULL)
	{
		Task[Copy_u8Priority]->state = CRTOS_u8_TASK_RUNNING;
	}
}
void CRTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	if (Task[Copy_u8Priority] != CRTOS_u8_NULL)
	{
		Task[Copy_u8Priority]->state = CRTOS_u8_TASK_DELETED;
	}
}
void CRTOS_voidOVFCount(void)
{
	OVF_count++;
	if(OVF_count == 2) { // 1 ms
		OVF_count = 0;
		TCNT0 = 192;
		CRTOS_voidScheduler();
	}
}


