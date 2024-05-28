/*************************************************************************/ /**
 * @file    intCtrl_cfg.h
 *
 * @brief   This file contains user's configurations for interrupts
 *          control driver for tm4c123gh6pm MCU.
 *
 * @version V1.0
 * @date    20 May 2024
 *
 * @author  Nabil Yasser - Embedded Software Engineer
 *
 * @author  GitHub: https://github.com/nabil-yasser
 *
 *****************************************************************************/

#ifndef INTCTRL_CFG_H
#    define INTCTRL_CFG_H

extern intCtrl_config_st g_intConfigurations[];

/* ========================================================================= */
/* ================            USER CONFIGURATIONS          ================ */
/* ========================================================================= */

/*************************************************************************/ /**
 * @brief Enable/Disable global exceptions except non-maskable interrupts.
 *
 * Possible values:
 * - 0 : Disable
 * - 1 : Enable (default)
 *
 * @warning This setting must be maintained carefully, this disable all
 *          exceptions excluding non-maskable interrupts.
 *****************************************************************************/
#    define INTCTRL_FAULTMASK 1

/*************************************************************************/ /**
 * @brief Enable/Disable priority programmable interrupts.
 *
 * Possible values:
 * - 0 : Disable
 * - 1 : Enable (default)
 *
 * @warning This setting must be maintained carefully!
 *****************************************************************************/
#    define INTCTRL_PRIMASK 1

/*************************************************************************/ /**
 * @brief Changes the offset of vector table
 *
 * Possible values:
 * 32-bit value indicating the offset of the vector table (default:
 *0x00000000)
 *
 * @note When configuring the OFFSET field, the offset must be aligned to
 *the number of exception entries in the vector table. Because there are 138
 *       interrupts, the offset must be aligned on a 1024-byte boundary.
 *****************************************************************************/
#    define INTCTRL_VTABLE_OFFSET 0x00000000

/*************************************************************************/ /**
 * @brief Configures the priority grouping for the exception model
 *
 * Possible values:
 * - 0 : xxx [Group priority: 8] - [Subpriorities: 1]. (default)
 * - 1 : xxy [Group priority: 4] - [Subpriorities: 2].
 * - 2 : xyy [Group priority: 2] - [Subpriorities: 4].
 * - 3 : yyy [Group priority: 1] - [Subpriorities: 8].
 *
 * @note An x denotes a group priority field bit, and a y denotes a
 *       subpriority field bit
 *****************************************************************************/
#    define INTCTRL_PRIGROUP 0

#endif /* INTCTRL_CFG_H */

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
