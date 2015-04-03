/*****************************************************************************/
/* STM is an example on using SCHED                                          */
/* amislam - 28 Mach 2015                                                    */
/*****************************************************************************/
#ifndef _STM_H_
#define _STM_H_

//#define STM_TIME_MEASUREMENTS_ENABLED

extern void STM_action_STATE_00(void);
extern void STM_action_STATE_01(void);
extern void STM_action_STATE_02(void);
extern void STM_action_STATE_03(void);
extern void STM_action_STATE_04(void);
extern void STM_action_STATE_05(void);
extern void STM_action_STATE_06(void);
extern void STM_action_STATE_07(void);
extern void STM_action_STATE_08(void);
extern void STM_action_STATE_09(void);
extern void STM_action_STATE_10(void);
extern void STM_action_STATE_11(void);
extern void STM_action_STATE_12(void);
extern void STM_action_STATE_13(void);
extern void STM_action_STATE_14(void);
extern void STM_action_STATE_15(void);
extern void STM_action_STATE_16(void);
extern void STM_action_STATE_17(void);
extern void STM_action_STATE_18(void);
extern void STM_action_STATE_19(void);
extern void STM_action_STATE_20(void);
extern void STM_action_STATE_21(void);
extern void STM_action_STATE_22(void);
extern void STM_action_STATE_23(void);
extern void STM_action_STATE_24(void);
extern void STM_action_STATE_25(void);
extern void STM_action_STATE_26(void);
extern void STM_action_STATE_27(void);
extern void STM_action_STATE_28(void);
extern void STM_action_STATE_29(void);
extern void STM_action_STATE_30(void);
extern void STM_action_STATE_31(void);

#ifdef STM_TIME_MEASUREMENTS_ENABLED
/*! This should be replaced by a TCNT or something */
static unsigned short int _TCNT = 0;
#define clock() _TCNT++
extern unsigned short int STM_TaskDuration[SCHED_STATES_NUM];
extern unsigned short int STM_startTime;
#define STM_TimeMeasurementStart(task_id)  do{STM_startTime = clock();} while(0)
#define STM_TimeMeasurementStop(task_id)    \
do{                                         \
   unsigned short int duration;             \
   duration = (clock()-STM_startTime);      \
   if(duration > STM_TaskDuration[task_id]) \
   {                                        \
      STM_TaskDuration[task_id] = clock();  \
   }                                        \
}while(0)

#endif /* STM_TIME_MEASUREMENTS_ENABLED */

#endif /* _STM_H_ */

