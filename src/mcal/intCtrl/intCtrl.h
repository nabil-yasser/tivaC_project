/******************************************************************************
 * @file    intCtrl.h
 *
 * @brief   This file contains interrupts interfacing for tm4c123gh6pm MCU
 *
 * @version V1.0
 * @date    20 May 2024
 *
 * @author  Nabil Yasser - Embedded Software Engineer
 *
 * @author  GitHub: https://github.com/nabil-yasser
 *
 *****************************************************************************/

#ifndef INTCTRL_H
#    define INTCTRL_H

/* ========================================================================= */
/* ================                 INCLUDES                ================ */
/* ========================================================================= */

#    include "../../utils/mcu_registers.h"

/* ========================================================================= */
/* ================     GLOBAL DATA TYPES AND STRUCTURES    ================ */
/* ========================================================================= */

typedef enum intCtrl_priorityLevel_et
{
    // When user configure priority grouping to xxx (8 Groups & 1 Subgroups)
    XXX_GROUP0_SUB0 = 0,
    XXX_GROUP1_SUB0 = 1,
    XXX_GROUP2_SUB0 = 2,
    XXX_GROUP3_SUB0 = 3,
    XXX_GROUP4_SUB0 = 4,
    XXX_GROUP5_SUB0 = 5,
    XXX_GROUP6_SUB0 = 6,
    XXX_GROUP7_SUB0 = 7,

    // When user configure priority grouping to xx.y (4 Groups & 2 Subgroups)
    XXY_GROUP0_SUB0 = 0,
    XXY_GROUP0_SUB1 = 1,
    XXY_GROUP1_SUB0 = 2,
    XXY_GROUP1_SUB1 = 3,
    XXY_GROUP2_SUB0 = 4,
    XXY_GROUP2_SUB1 = 5,
    XXY_GROUP3_SUB0 = 6,
    XXY_GROUP3_SUB1 = 7,

    // When user configure priority grouping to x.yy (2 Groups & 4 Subgroups)
    XYY_GROUP0_SUB0 = 0,
    XYY_GROUP0_SUB1 = 1,
    XYY_GROUP0_SUB2 = 2,
    XYY_GROUP0_SUB3 = 3,
    XYY_GROUP1_SUB0 = 4,
    XYY_GROUP1_SUB1 = 5,
    XYY_GROUP1_SUB2 = 6,
    XYY_GROUP1_SUB3 = 7,

    // When user configure priority grouping to yyy (1 Groups & 8 Subgroups)
    YYY_GROUP0_SUB0 = 0,
    YYY_GROUP0_SUB1 = 1,
    YYY_GROUP0_SUB2 = 2,
    YYY_GROUP0_SUB3 = 3,
    YYY_GROUP0_SUB4 = 4,
    YYY_GROUP0_SUB5 = 5,
    YYY_GROUP0_SUB6 = 6,
    YYY_GROUP0_SUB7 = 7,
} intCtrl_priorityLevel_et;

typedef enum intCtrl_state_et
{
    INTCTRL_DISABLE,
    INTCTRL_ENABLE
} intCtrl_state_et;

typedef struct intCtrl_config_st
{
    IRQn_Type                etInterruptId;
    intCtrl_state_et         etInterruptState;
    intCtrl_priorityLevel_et etPriorityLevel;
} intCtrl_config_st;

/* ========================================================================= */
/* ================        GLOBAL FUNCTION PROTOTYPES       ================ */
/* ========================================================================= */

/******************************************************************************
 * @brief Initializes all system interrupts configurations based on user's
          chosen configurations in @c intCtrl_cfg.h file.
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Non Reentrant
 *
 * @param void This function doesn't take any parameters
 *
 * @return void
 *
 *****************************************************************************/
void intCtrl_init(void);

#endif /* INTCTRL_H */

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
