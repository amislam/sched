#ifndef _SCHED_H_
#define _SCHED_H_

#include "std_types.h"
#include "sched_cfg.h"

#define SCHED_INVALID_TASK_ID 1

extern void SCHED_ActivateAllTasks (void);
extern void SCHED_TerminateAllTasks(void);
extern void SCHED_ActivateTask     (sched_state_T state_id);
extern void SCHED_TerminateTask    (void);
extern bool SCHED_IsTaskActive     (sched_state_T state_id);
extern bool SCHED_IsAnyTaskActive  (void);
extern void SCHED_main             (void);
extern void SCHED_main_auto        (void);

#endif /* _SCHED_H_ */

