#ifndef _SCHED_CFG_H_
#define _SCHED_CFG_H_

#include "stm.h"
#include <stdio.h>

/*! Number of tasks */
#define SCHED_STATES_NUM 32

typedef void (* fpActions_T)(void);
const fpActions_T SCHED_actions[SCHED_STATES_NUM]; 

#define SCHED_ErrorHandler(errorn)     printf("ERROR number = 0x%x; ERROR flag = %d\n", errorn, SCHED_ErrorFlag)
#define SCHED_preTaskHook(task_id)
#define SCHED_postTaskHook(task_id)

/*! enum for states identifiers */
typedef enum {
   STATE_00=0,
   STATE_01,
   STATE_02,
   STATE_03,
   STATE_04,
   STATE_05,
   STATE_06,
   STATE_07,
   STATE_08,
   STATE_09,
   STATE_10,
   STATE_11,
   STATE_12,
   STATE_13,
   STATE_14,
   STATE_15,
   STATE_16,
   STATE_17,
   STATE_18,
   STATE_19,
   STATE_20,
   STATE_21,
   STATE_22,
   STATE_23,
   STATE_24,
   STATE_25,
   STATE_26,
   STATE_27,
   STATE_28,
   STATE_29,
   STATE_30,
   STATE_31,
} sched_state_T;

#endif /* _SCHED_CFG_H_ */

