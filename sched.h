/*****************************************************************************/
/* SCHED is a basic scheduler to distribute the load between up to 32      - */
/* 32 actions in background task of a super load to minimize periodic        */
/* actions jitter. It can serve as a core for a statemachine implementation. */
/* amislam - 28 Mach 2015                                                    */
/*****************************************************************************/

#ifndef _SCHED_H_
#define _SCHED_H_

#include "std_types.h"
#include "sched_cfg.h"

#define SCHED_INVALID_TASK_ID       0x01
#define SCHED_MULTIPLE_ACTIVATION   0x10
#define SCHED_INVALID_CONTEXT       0x20

#define SCHED_TerminatTask_API_ID   0x04

extern int SCHED_ErrorFlag;

<<<<<<< HEAD
=======
extern void SCHED_ActivateAllTasks (void);
extern void SCHED_TerminateAllTasks(void);
extern void SCHED_ActivateTask     (sched_state_T state_id);
extern void SCHED_TerminateTask    (void);
>>>>>>> 1afff9df5f0683bff1dabfe010a8ec77307926c5
extern bool SCHED_IsTaskActive     (sched_state_T state_id);
extern void SCHED_ActivateTask     (sched_state_T state_id);
extern void SCHED_TerminateTask    (void);
extern bool SCHED_IsAnyTaskActive  (void);
extern void SCHED_main_p           (void);
extern void SCHED_main_q           (void);

#endif /* _SCHED_H_ */

