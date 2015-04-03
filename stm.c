/*****************************************************************************/
/* STM is an example on using SCHED                                          */
/* amislam - 28 Mach 2015                                                    */
/*****************************************************************************/

#include "stdio.h"
#include "std_types.h"
#include "sched.h"
#include "stm.h"

/*! Variables used for tasks duration measurements */
#ifdef STM_TIME_MEASUREMENTS_ENABLED
u16 STM_TaskDuration[SCHED_STATES_NUM];
u16 STM_startTime;
#endif

/*** APPLICATION CODE EXAMPLE ***/

#define FUN(current, next) extern void STM_action_##current(void)     \
                           {                                          \
                              SCHED_ActivateTask(STATE_00);           \
                              printf("Task: %d\n", current);          \
                              SCHED_TerminateTask();                  \
                           }
/*                              SCHED_ActivateTask(next);               \
                              int i; for(i=0;i<256;i++);              \

*/
#define LAST_FUN(current)  extern void STM_action_##current(void)     \
                           {                                          \
                              printf("Task: %d\n", current);          \
                              SCHED_TerminateTask();                  \
                           }

LAST_FUN(STATE_00)

FUN(STATE_01, STATE_02)
FUN(STATE_02, STATE_03)
FUN(STATE_03, STATE_04)
FUN(STATE_04, STATE_05)
FUN(STATE_05, STATE_06)
FUN(STATE_06, STATE_07)
FUN(STATE_07, STATE_08)

FUN(STATE_08, STATE_09)
FUN(STATE_09, STATE_10)
FUN(STATE_10, STATE_11)
FUN(STATE_11, STATE_12)
FUN(STATE_12, STATE_13)
FUN(STATE_13, STATE_14)
FUN(STATE_14, STATE_15)
FUN(STATE_15, STATE_16)

FUN(STATE_16, STATE_17)
FUN(STATE_17, STATE_18)
FUN(STATE_18, STATE_19)
FUN(STATE_19, STATE_20)
FUN(STATE_20, STATE_21)
FUN(STATE_21, STATE_22)
FUN(STATE_22, STATE_23)
FUN(STATE_23, STATE_24)

FUN(STATE_24, STATE_25)
FUN(STATE_25, STATE_26)
FUN(STATE_26, STATE_27)
FUN(STATE_27, STATE_28)
FUN(STATE_28, STATE_29)
FUN(STATE_29, STATE_30)
FUN(STATE_30, STATE_31)
FUN(STATE_31, STATE_00)

