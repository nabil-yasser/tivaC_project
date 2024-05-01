/******************************************************************************
 * @file    macros.h
 *
 * @date    11 Feb 2024
 *
 * @author  Nabil Yasser - Embedded Software Engineer
 *
 * @author  GitHub: https://github.com/nabil-yasser
 *
 * @brief   Includes all function-like macros required for bit manipulation
 *
 *****************************************************************************/

#ifndef MACROS_H
#define MACROS_H

/* ========================================================================= */
/* ================          GLOBAL FUNCTION MACROS         ================ */
/* ========================================================================= */

#define SET_BIT(reg, bit)    reg |= (1 << bit)
#define CLEAR_BIT(reg, bit)  reg &= ~(1 << bit)
#define GET_BIT(reg, bit)    ((reg >> bit) & 0x01)
#define TOGGLE_BIT(reg, bit) reg ^= (1 << bit)

#endif /* MACROS_H */

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
