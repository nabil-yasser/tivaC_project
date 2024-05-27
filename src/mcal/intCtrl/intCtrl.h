/*************************************************************************/ /**
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
    XXX_GROUP0_SUB0 = 0, ///< Priority 0 & Subpriority 0
    XXX_GROUP1_SUB0 = 1, ///< Priority 1 & Subpriority 0
    XXX_GROUP2_SUB0 = 2, ///< Priority 2 & Subpriority 0
    XXX_GROUP3_SUB0 = 3, ///< Priority 3 & Subpriority 0
    XXX_GROUP4_SUB0 = 4, ///< Priority 4 & Subpriority 0
    XXX_GROUP5_SUB0 = 5, ///< Priority 5 & Subpriority 0
    XXX_GROUP6_SUB0 = 6, ///< Priority 6 & Subpriority 0
    XXX_GROUP7_SUB0 = 7, ///< Priority 7 & Subpriority 0

    XXY_GROUP0_SUB0 = 0, ///< Priority 0 & Subpriority 0
    XXY_GROUP0_SUB1 = 1, ///< Priority 0 & Subpriority 1
    XXY_GROUP1_SUB0 = 2, ///< Priority 1 & Subpriority 0
    XXY_GROUP1_SUB1 = 3, ///< Priority 1 & Subpriority 1
    XXY_GROUP2_SUB0 = 4, ///< Priority 2 & Subpriority 0
    XXY_GROUP2_SUB1 = 5, ///< Priority 2 & Subpriority 1
    XXY_GROUP3_SUB0 = 6, ///< Priority 3 & Subpriority 0
    XXY_GROUP3_SUB1 = 7, ///< Priority 3 & Subpriority 1

    XYY_GROUP0_SUB0 = 0, ///< Priority 0 & Subpriority 0
    XYY_GROUP0_SUB1 = 1, ///< Priority 0 & Subpriority 1
    XYY_GROUP0_SUB2 = 2, ///< Priority 0 & Subpriority 2
    XYY_GROUP0_SUB3 = 3, ///< Priority 0 & Subpriority 3
    XYY_GROUP1_SUB0 = 4, ///< Priority 1 & Subpriority 0
    XYY_GROUP1_SUB1 = 5, ///< Priority 1 & Subpriority 1
    XYY_GROUP1_SUB2 = 6, ///< Priority 1 & Subpriority 2
    XYY_GROUP1_SUB3 = 7, ///< Priority 1 & Subpriority 3

    YYY_GROUP0_SUB0 = 0, ///< Priority 0 & Subpriority 0
    YYY_GROUP0_SUB1 = 1, ///< Priority 0 & Subpriority 1
    YYY_GROUP0_SUB2 = 2, ///< Priority 0 & Subpriority 2
    YYY_GROUP0_SUB3 = 3, ///< Priority 0 & Subpriority 3
    YYY_GROUP0_SUB4 = 4, ///< Priority 0 & Subpriority 4
    YYY_GROUP0_SUB5 = 5, ///< Priority 0 & Subpriority 5
    YYY_GROUP0_SUB6 = 6, ///< Priority 0 & Subpriority 6
    YYY_GROUP0_SUB7 = 7, ///< Priority 0 & Subpriority 7
} intCtrl_priorityLevel_et;

typedef enum intCtrl_state_et
{
    INTCTRL_DISABLE, ///< Diable interrupt
    INTCTRL_ENABLE   ///< Enable interrupt
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

/*************************************************************************/ /**
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
