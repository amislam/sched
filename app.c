#include <stdio.h>
#include "std_types.h"
#include "sched.h"

#define SUPER_LOOP 100

void sched()
{
   SCHED_ActivateTask(STATE_00);
   SCHED_ActivateTask(STATE_01);
   SCHED_ActivateTask(STATE_02);
   SCHED_ActivateTask(STATE_03);
   SCHED_ActivateTask(STATE_04);
   SCHED_ActivateTask(STATE_05);
   SCHED_ActivateTask(STATE_06);
   SCHED_ActivateTask(STATE_07);
   SCHED_ActivateTask(STATE_08);
   SCHED_ActivateTask(STATE_09);
   SCHED_ActivateTask(STATE_10);
   SCHED_ActivateTask(STATE_11);
   SCHED_ActivateTask(STATE_12);
   SCHED_ActivateTask(STATE_13);
   SCHED_ActivateTask(STATE_14);
   SCHED_ActivateTask(STATE_15);
   SCHED_ActivateTask(STATE_16);
   SCHED_ActivateTask(STATE_17);
   SCHED_ActivateTask(STATE_18);
   SCHED_ActivateTask(STATE_19);
   SCHED_ActivateTask(STATE_20);
   SCHED_ActivateTask(STATE_21);
   SCHED_ActivateTask(STATE_22);
   SCHED_ActivateTask(STATE_23);
   SCHED_ActivateTask(STATE_24);
   SCHED_ActivateTask(STATE_25);
   SCHED_ActivateTask(STATE_26);
   SCHED_ActivateTask(STATE_27);
   SCHED_ActivateTask(STATE_28);
   SCHED_ActivateTask(STATE_29);
   SCHED_ActivateTask(STATE_30);
   SCHED_ActivateTask(STATE_31);
   while(SCHED_IsAnyTaskActive())
   {
      SCHED_main_p();
   }
}

void sched_fast()
{
   SCHED_ActivateTask(STATE_00);
   SCHED_ActivateTask(STATE_01);
   SCHED_ActivateTask(STATE_02);
   SCHED_ActivateTask(STATE_03);
   SCHED_ActivateTask(STATE_04);
   SCHED_ActivateTask(STATE_05);
   SCHED_ActivateTask(STATE_06);
   SCHED_ActivateTask(STATE_07);
   SCHED_ActivateTask(STATE_08);
   SCHED_ActivateTask(STATE_09);
   SCHED_ActivateTask(STATE_10);
   SCHED_ActivateTask(STATE_11);
   SCHED_ActivateTask(STATE_12);
   SCHED_ActivateTask(STATE_13);
   SCHED_ActivateTask(STATE_14);
   SCHED_ActivateTask(STATE_15);
   SCHED_ActivateTask(STATE_16);
   SCHED_ActivateTask(STATE_17);
   SCHED_ActivateTask(STATE_18);
   SCHED_ActivateTask(STATE_19);
   SCHED_ActivateTask(STATE_20);
   SCHED_ActivateTask(STATE_21);
   SCHED_ActivateTask(STATE_22);
   SCHED_ActivateTask(STATE_23);
   SCHED_ActivateTask(STATE_24);
   SCHED_ActivateTask(STATE_25);
   SCHED_ActivateTask(STATE_26);
   SCHED_ActivateTask(STATE_27);
   SCHED_ActivateTask(STATE_28);
   SCHED_ActivateTask(STATE_29);
   SCHED_ActivateTask(STATE_30);
   SCHED_ActivateTask(STATE_31);
   while(SCHED_IsAnyTaskActive())
   {
      SCHED_main_q();
   }
}
void pp(void)
{
                              int i; for(i=0;i<256;i++);
}
void direct()
{
   int i;
   for(i=0;i<32;i++) pp();
}

int main(void)
{
   int i=0;

   for(i=0; i<SUPER_LOOP; i++)
   {
      sched();
//      sched_fast();
      direct();
   }

   return 0;
}

