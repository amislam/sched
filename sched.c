/*****************************************************************************/
/* SCHED is a basic scheduler to distribute the load between up to 32      - */
/* 32 actions in background task of a super load to minimize periodic        */
/* actions jitter. It can serve as a core for a statemachine implementation. */
/* amislam - 28 Mach 2015                                                    */
/*****************************************************************************/
#include "sched.h"
#include "sched_cfg.h"
#include "std_types.h"

static sched_state_T active_state    = 0;
static sched_state_T current_state   = 0;
static sched_state_T requested_state = 0;
int SCHED_ErrorFlag;

#if (SCHED_STATES_NUM < 9)
typedef u8 status_word_T;
#elif (SCHED_STATES_NUM < 17)
typedef u16 status_word_T;
#elif (SCHED_STATES_NUM < 33)
typedef u32 status_word_T;
#else
#error "SCHED module is optimized for 16 or 32 states"
#endif

static status_word_T sched_states_activation = 0x00;

extern bool SCHED_IsAnyTaskActive  (void)  {return (sched_states_activation == 0)?0:1;}

extern void SCHED_ActivateTask(sched_state_T state_id)
{
   /*! protect against invalid task id     */
   if(state_id >= SCHED_STATES_NUM)
   {
      SCHED_ErrorFlag = (u32) state_id;
      SCHED_ErrorHandler(SCHED_INVALID_TASK_ID);
   } /*! protect against multiple activation */
   else if (sched_states_activation & (1 << state_id))
   {
      SCHED_ErrorFlag = (u32) state_id;
      SCHED_ErrorHandler(SCHED_MULTIPLE_ACTIVATION);
   }
   else
   {
      /*! set the task activation bit */
      sched_states_activation |= (1 << state_id);
      /*! update scheduler with the higher priority task */
      if(state_id < requested_state) requested_state = state_id;
   }
}

extern void SCHED_TerminateTask(void)
{
   /*! SCHED_TerminateTask shall be called only from the task */
   if(active_state != current_state)
   {
      SCHED_ErrorFlag = (u32) SCHED_TerminatTask_API_ID;
      SCHED_ErrorHandler(SCHED_INVALID_CONTEXT);
   }
   else
   { 
      /*! Terminate the task by clearing its activation bit */
      sched_states_activation &= (status_word_T) (~(1 << active_state));
   }
}

extern bool SCHED_IsTaskActive(sched_state_T state_id)
{
   bool retVal = 0;
   if(state_id < SCHED_STATES_NUM)
   {
      retVal = (sched_states_activation & (1 << state_id)) == 0? 0:1;
   }
   else
   {
      SCHED_ErrorFlag = (u32) state_id;
      SCHED_ErrorHandler(SCHED_INVALID_TASK_ID);
   }
   return retVal;
}

extern void SCHED_main_p(void)
{
   u8 index;

   current_state = requested_state;

   if(0 != (sched_states_activation & (1 << current_state)))
   {
      /*! This is not a real preTaskHook but pre-action execution */
      SCHED_preTaskHook(current_state);
      active_state = current_state;
      requested_state = current_state;
      SCHED_actions[current_state]();

      /*! update scheduler with the higher priority task */
      SCHED_postTaskHook(current_state);
   }

   current_state = requested_state;

   /* The highest priority task shall be finished before any other task can start */
   if(0 == (sched_states_activation & (1 << current_state)))
   {
      /*! after a task termination, the next priority task shall be executed */
      for(index=current_state; index<SCHED_STATES_NUM; index++)
      {
          if(sched_states_activation & (1 << index))
          {
             current_state   = index;
             requested_state = index;
             break;
          }
      }
   }
}

extern void SCHED_main_q(void)
{
   u8 hit;
   u8 index;

   /*! This is not a real preTaskHook but pre-action execution */
   SCHED_preTaskHook(current_state);

   active_state = current_state;
   SCHED_actions[current_state]();

   SCHED_postTaskHook(current_state);

   hit = 0;
   for(index=(current_state+1); index<SCHED_STATES_NUM; index++)
   {
       if(sched_states_activation & (1 << index))
       {
          hit = 1;
          current_state = index;
          break;
       }
   }
   if(!hit)
   {
      for(index=0; index<current_state; index++)
      {
         if(sched_states_activation & (1 << index))
         {
            hit = 1;
            current_state = index;
            break;
         }
      }
   }
}

