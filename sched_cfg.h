#ifndef _SCHED_CFG_H_
#define _SCHED_CFG_H_

#include "sched.h"

#define SCHED_STATES_NUM 32
typedef void (* SCHED_action_T)(void);
typedef enum {
   TOTO_STATE_00=0,
   TOTO_STATE_01,
   TOTO_STATE_02,
   TOTO_STATE_03,
   TOTO_STATE_04,
   TOTO_STATE_05,
   TOTO_STATE_06,
   TOTO_STATE_07,
   TOTO_STATE_08,
   TOTO_STATE_09,
   TOTO_STATE_10,
   TOTO_STATE_11,
   TOTO_STATE_12,
   TOTO_STATE_13,
   TOTO_STATE_14,
   TOTO_STATE_15,
   TOTO_STATE_16,
   TOTO_STATE_17,
   TOTO_STATE_18,
   TOTO_STATE_19,
   TOTO_STATE_20,
   TOTO_STATE_21,
   TOTO_STATE_22,
   TOTO_STATE_23,
   TOTO_STATE_24,
   TOTO_STATE_25,
   TOTO_STATE_26,
   TOTO_STATE_27,
   TOTO_STATE_28,
   TOTO_STATE_29,
   TOTO_STATE_30,
   TOTO_STATE_31,
} sched_state_T;

extern const SCHED_action_T SCHED_actions[SCHED_STATES_NUM];

extern void delay(u32 counts);

#define SCHED_Through_Exception(errorn)

/*! if measurements are enaled; user shall define
**  preTaskHook, postTaskHook, and the variables
**  needed to measure tasks duration.
**/
#define SCHED_MEASUREMENTS_ENABLED
#ifdef SCHED_MEASUREMENTS_ENABLED
/*! This should be replaced by a TCNT or something */
#define clock() 232
extern u16 SCHED_TaskDuration[SCHED_STATES_NUM];
extern u16 SCHED_preTaskTime;
#define SCHED_preTaskHook(task_id)  do{SCHED_preTaskTime = clock();} while(0)
#define SCHED_postTaskHook(task_id)           \
do{                                           \
   u16 duration;                              \
   duration = (clock()-SCHED_preTaskTime);    \
   if(duration > SCHED_TaskDuration[task_id]) \
   {                                          \
      SCHED_TaskDuration[task_id] = clock();  \
   }                                          \
}while(0)

#else
#define SCHED_preTaskHook(task_id)
#define SCHED_postTaskHook(task_id)
#endif

#endif /* _SCHED_CFG_H_ */

