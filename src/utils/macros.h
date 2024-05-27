/*************************************************************************/ /**
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

#include <stdint.h>

/* ========================================================================= */
/* ================          GLOBAL FUNCTION MACROS         ================ */
/* ========================================================================= */

#define BITBAND_REGION_BASE      (0x20000000UL)
#define BITBAND_ALIASE_BASE      (0x22000000UL)
#define BITBAND_PERI_REGION_BASE (0x40000000UL)
#define BITBAND_PERI_ALIASE_BASE (0x42000000UL)

#define SET_BIT(reg, bit)        (reg |= (1 << bit))
#define CLEAR_BIT(reg, bit)      (reg &= ~(1 << bit))
#define GET_BIT(reg, bit)        ((reg >> bit) & 0x01)
#define TOGGLE_BIT(reg, bit)     (reg ^= (1 << bit))
#define isConfigDisabled(config) (config == 0)
#define isConfigEnabled(config)  (config == 1)

/* Address of register is casted to uint32_t so that we can do arithmatic
 * operations on it
 */
#define BITBAND_REG(reg, bit)                                                  \
    (*(uint32_t*)(BITBAND_ALIASE_BASE                                          \
                  + (((uint32_t) & reg - BITBAND_REGION_BASE) * 32UL)          \
                  + (bit * 4UL)))

#define BITBAND_PERIREG(reg, bit)                                              \
    (*(uint32_t*)(BITBAND_PERI_ALIASE_BASE                                     \
                  + (((uint32_t) & reg - BITBAND_PERI_REGION_BASE) * 32UL)     \
                  + (bit * 4UL)))

#endif /* MACROS_H */

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
