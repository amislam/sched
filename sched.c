#include "sched.h"
#include "sched_cfg.h"
#include "std_types.h"

#if (SCHED_STATES_NUM < 9)
static u8  sched_states_activation = 0x00;
#elif (SCHED_STATES_NUM < 17)
static u16 sched_states_activation = 0x00;
#elif (SCHED_STATES_NUM < 33)
static u32 sched_states_activation = 0x00;
#else
#error "SCHED module is optimized for 16 or 32 states"
#endif

extern void SCHED_ActivateAllTasks (void)  {sched_states_activation = ((1<<(SCHED_STATES_NUM)) - 1);}
extern void SCHED_TerminateAllTasks(void)  {sched_states_activation = 0;}
extern bool SCHED_IsAnyTaskActive  (void)  {return (sched_states_activation != 0);}

extern void SCHED_ActivateTask(sched_state_T state_id)
{
   if(state_id < SCHED_STATES_NUM)
   {
      sched_states_activation |= (1 << state_id);
   }
   else
   {
      SCHED_Through_Exception(SCHED_INVALID_TASK_ID);
   }
}

extern void SCHED_TerminateTask(sched_state_T state_id)
{
   if(state_id < SCHED_STATES_NUM)
   {
      sched_states_activation &= (~(1 << state_id));
   }
   else
   {
      SCHED_Through_Exception(SCHED_INVALID_TASK_ID);
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
      SCHED_Through_Exception(SCHED_INVALID_TASK_ID);
   }
   return retVal;
}

extern void SCHED_main(void)
{
   static sched_state_T current_state = 0;
   u8     index;
   bool   hit;

   hit = 0;

   for(index=0; index<SCHED_STATES_NUM; index++)
   {
       /* if current state is active, call its handler */
       if(sched_states_activation & (1 << current_state))
       {
          SCHED_preTaskHook(current_state);
          SCHED_actions[current_state]();
          SCHED_postTaskHook(current_state);
          hit = 1;
       }

       /* update next state index */
       if (current_state < (SCHED_STATES_NUM-1))
       {
          current_state++;
       }
       else
       {
          current_state = 0;
       }

       if(hit == 1) break;
   }
}

extern void SCHED_main_auto(void)
{
   sched_state_T state_index;
 
   for(state_index=0; state_index<SCHED_STATES_NUM; state_index++)
   {
       /* if current state is active, call its handler */
       if(sched_states_activation & (1 << state_index))
       {
          SCHED_actions[state_index]();
       }
   }
}

