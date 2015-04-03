<<<<<<< HEAD
=======
#include "stdio.h"
#include "std_types.h"
#include "sched.h"
#include "sched_cfg.h"

/*! Variables used for tasks duration measurements */
#ifdef SCHED_MEASUREMENTS_ENABLED
u16 SCHED_TaskDuration[SCHED_STATES_NUM]={0};
u16 SCHED_preTaskTime;
#endif

/*** APPLICATION CODE EXAMPLE ***/

#define FUN(current, next) void state_##current(void) {printf("Task #: %d\n", current); SCHED_ActivateTask(next); SCHED_TerminateTask(); }
#define LAST_FUN(current)  void state_##current(void) {printf("Task #: %d\n", current); SCHED_TerminateTask(); }
>>>>>>> 1afff9df5f0683bff1dabfe010a8ec77307926c5

#include "stm.h"
#include "sched_cfg.h"

/*! function pointer type */
const fpActions_T SCHED_actions[SCHED_STATES_NUM] = 
{
   &STM_action_STATE_00,
   &STM_action_STATE_01,
   &STM_action_STATE_02,
   &STM_action_STATE_03,
   &STM_action_STATE_04,
   &STM_action_STATE_05,
   &STM_action_STATE_06,
   &STM_action_STATE_07,
   &STM_action_STATE_08,
   &STM_action_STATE_09,
   &STM_action_STATE_10,
   &STM_action_STATE_11,
   &STM_action_STATE_12,
   &STM_action_STATE_13,
   &STM_action_STATE_14,
   &STM_action_STATE_15,
   &STM_action_STATE_16,
   &STM_action_STATE_17,
   &STM_action_STATE_18,
   &STM_action_STATE_19,
   &STM_action_STATE_20,
   &STM_action_STATE_21,
   &STM_action_STATE_22,
   &STM_action_STATE_23,
   &STM_action_STATE_24,
   &STM_action_STATE_25,
   &STM_action_STATE_26,
   &STM_action_STATE_27,
   &STM_action_STATE_28,
   &STM_action_STATE_29,
   &STM_action_STATE_30,
   &STM_action_STATE_31,
};

