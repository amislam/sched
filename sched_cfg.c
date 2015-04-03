
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

