/******************************************************************************
 * @file    mcu.c
 *
 * @brief   This file contains mcu control driver implementation which
 *          controls clock source and oscillator value.
 *
 * @version V1.0
 * @date    25 May 2024
 *
 * @author  Nabil Yasser - Embedded Software Engineer
 *
 * @author  GitHub: https://github.com/nabil-yasser
 *
 *****************************************************************************/

/* ========================================================================= */
/* ================                 INCLUDES                ================ */
/* ========================================================================= */

#include "mcu.h"
#include "../../config/mcu_cfg.h"
#include "../../utils/macros.h"
#include "../../utils/mcu_registers.h"

/* ========================================================================= */
/* ================     LOCAL MACROS CONSTANT/FUNCTIONS     ================ */
/* ========================================================================= */

#define BYPASS_BIT_OFFSET    11UL
#define OSCSRC_BITS_OFFSET   4UL
#define XTAL_BITS_OFFSET     6UL
#define PWRDN_BIT_OFFSET     13UL
#define SYSDIV_BITS_OFFSET   23UL
#define USESYSDIV_BIT_OFFSET 22UL
#define RCC2_ENBIT_OFFSET    31UL
#define PLLLRIS_BIT_OFFSET   6UL
#define PLLLMIS_BIT_OFFSET   6UL

/* ========================================================================= */
/* ================            GLOBAL FUNCTIONS             ================ */
/* ========================================================================= */

void mcu_init(void)
{
// Setting BYPASS bit and clearing the USESYS bit in RCC register
#if (isConfigDisabled(MCU_PLL_STATE))
    SET_BIT(SYSCTL->RCC, BYPASS_BIT_OFFSET);
#elif (isConfigEnabled(MCU_PLL_STATE))
    // Nothing to do
#else
    #error "Invalid configuration value, only [0, 1] allowed."
#endif

// Select crystal value and oscillator source and clear the PWRDN bit in RCC
#if (MCU_OSCSRC >= 0 && MCU_OSCSRC <= 3)
    SYSCTL->RCC |= (MCU_OSCSRC << OSCSRC_BITS_OFFSET);
#else
    #error "Invalid configuration value, only [0 ~ 3] allowed."
#endif

#if (MCU_CRYSTAL_VALUE >= 0 && MCU_CRYSTAL_VALUE <= 20)
    SYSCTL->RCC |= ((MCU_CRYSTAL_VALUE + 6UL) << XTAL_BITS_OFFSET);
#endif

#if (isConfigDisabled(MCU_PLL_STATE))
    // Nothing to do
#elif (isConfigEnabled(MCU_PLL_STATE))
    CLEAR_BIT(SYSCTL->RCC, PWRDN_BIT_OFFSET);
#else
    #error "Invalid configuration value, only [0, 1] allowed."
#endif

// Select the desired system divider SYSDIV in RCC and set the USESYS bit
#if (isConfigEnabled(MCU_USESYSDIV) || isConfigEnabled(MCU_PLL_STATE))
    #if (MCU_SYSDIV_VALUE >= 0 && MCU_SYSDIV_VALUE <= 15)
    SYSCTL->RCC |= (MCU_SYSDIV_VALUE << SYSDIV_BITS_OFFSET);
    #else
        #error "Invalid configuration value, only [0 ~ 15] allowed."
    #endif

    #if (isConfigDisabled(MCU_USESYSDIV))
        // Nothing to do
    #elif (isConfigEnabled(MCU_USESYSDIV))
    SET_BIT(SYSCTL->RCC, USESYSDIV_BIT_OFFSET);
    #endif
#endif

// Wait for the PLL to lock by polling the PLLLRIS bit in RIS register
#if (isConfigEnabled(MCU_PLL_STATE))
    while (GET_BIT(SYSCTL->RIS, PLLLRIS_BIT_OFFSET) == 0)
        ;
#endif

// Enable use of PLL by clearing BYPASS bit
#if (isConfigEnabled(MCU_PLL_STATE))
    CLEAR_BIT(SYSCTL->RCC, BYPASS_BIT_OFFSET);
#endif
}

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
