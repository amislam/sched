#include <stdio.h>
#include "std_types.h"
#include "sched.h"

#define SUPER_LOOP 100000

void sched()
{
   SCHED_ActivateTask(TOTO_STATE_00);
   while(SCHED_IsAnyTaskActive())
   {
      SCHED_main();
   }
}

void sched_fast()
{
   SCHED_ActivateTask(TOTO_STATE_00);
   while(SCHED_IsAnyTaskActive())
   {
      SCHED_main_auto();
   }
}

void direct()
{
   delay(8192);
}

int main(void)
{
   int i=0;

   for(i=0; i<SUPER_LOOP; i++)
   {
      sched();
      sched_fast();;
      direct();
   }

   return 0;
}

