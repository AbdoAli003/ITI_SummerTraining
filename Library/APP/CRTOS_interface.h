#ifndef APP_CRTOS_INTERFACE_H_
#define APP_CRTOS_INTERFACE_H_

#define CRTOS_u8_NULL  			0
#define CRTOS_u8_TASK_RUNNING 	1
#define CRTOS_u8_TASK_PAUSED 	0
#define CRTOS_u8_TASK_DELETED 	2


typedef struct
{
	u32 first_delay;
	u32 periodicity;
	void (*PtrFunc)(void);
	u8 state;
} Task_t;

void CRTOS_voidInit(void);
void CRTOS_voidCreateTask(Task_t* TaskPointer, u8 Task_Priority);
void CRTOS_voidScheduler(void);
void CRTOS_voidOVFCount(void);
void CRTOS_voidSuspendTask(u8 Copy_u8Priority);
void CRTOS_voidStartTask(u8 Copy_u8Priority);
void CRTOS_voidDeleteTask(u8 Copy_u8Priority);




#endif /* APP_CRTOS_INTERFACE_H_ */
