/*************************************************************************/ /**
 * @file    wdt.c
 * 
 * @brief   Contains the watchdog timer 1 driver implementation
 * 
 * @version V1.0
 * @date    28 May 2024
 * 
 * @author  Nabil Yasser - Embedded Software Engineer
 * 
 * @author  GitHub: https://github.com/nabil-yasser
 * 
 * @todo    Implement loadValue function to handle using WDT0 (system clock)
 *          situation, for now, the user must be enter the value in @c wdt.c
 * 
 *****************************************************************************/

/* ========================================================================= */
/* ================                 INCLUDES                ================ */
/* ========================================================================= */

#include "wdt.h"
#include "../../config/wdt_cfg.h"
#include "../../utils/macros.h"
#include "../../utils/mcu_registers.h"

/* ========================================================================= */
/* ================     LOCAL MACROS CONSTANT/FUNCTIONS     ================ */
/* ========================================================================= */

#define WDT_LOCK           0x00000000UL
#define WDT_UNLOCK         0x1ACCE551UL
#define NUMBER_OF_WDT      2UL
#define WRC_BIT_OFFSET     31UL
#define INTTYPE_BIT_OFFSET 2UL
#define RESEN_BIT_OFFSET   1UL
#define INTEN_BIT_OFFSET   0UL
#define PIOSC_FREQUENCY    16000000

#if (WDT_USEDWATCHDOG == 0)
#    define WATCHDOG WATCHDOG0
#elif (WDT_USEDWATCHDOG == 1)
#    define WATCHDOG WATCHDOG1
#else
#    error "Invalid WDT_USEDWATCHDOG configurations, only [0, 1] allowed."
#endif

/* ========================================================================= */
/* ================     LOCAL DATA TYPES AND STRUCTURES     ================ */
/* ========================================================================= */

/* ========================================================================= */
/* ================    GLOBAL DATA TYPES AND STRUCTURES     ================ */
/* ========================================================================= */

/* ========================================================================= */
/* ================        LOCAL FUNCTION PROTOTYPES        ================ */
/* ========================================================================= */

void static loadValue(uint32_t ui32Timeout);

/* ========================================================================= */
/* ================             LOCAL FUNCTIONS             ================ */
/* ========================================================================= */

/*************************************************************************/ /**
 * @brief Loads the WDT with the value depending on clock value
 * 
 * Sync/Async: Synchronous
 * 
 * Reentrancy: Non Reentrant
 * 
 * @param[in] ui32Timeout Time for resetting the WDT in milliseconds
 * 
 * @note This funciton doesn't work for WDT0 yet, you must enter the value
 *       of WDT manually based on clock configurations for your system
 *       depending on this formula (ui32Timeout / 1000.0) * [SystemFrequency]
 * 
 *****************************************************************************/
void static loadValue(uint32_t ui32Timeout)
{
    uint32_t ui32WdtLoadValue = (ui32Timeout / 1000.0) * PIOSC_FREQUENCY;

#if (WDT_USEDWATCHDOG == 0)
    WATCHDOG->LOAD = 0x00000000; // This value must be written by user
#    warning                                                                   \
        "loadValue function doesn't work for WATCHDOG TIMER 0 yet, you need to go and put the value by yourself."
#elif (WDT_USEDWATCHDOG == 1)
    WATCHDOG->LOAD = ui32WdtLoadValue;
#endif
}

/* ========================================================================= */
/* ================            GLOBAL FUNCTIONS             ================ */
/* ========================================================================= */

void wdt_init(void)
{
#if (isConfigEnabled(WDT_STATUS))
    // Load WDTLOAD register with the desired timer load value
    loadValue((uint32_t)WDT_LOADVALUE);

//  If WDT1, wait for the WRC bit in the WDTCTL register to be set
#    if (WDT_USEDWATCHDOG == 1)
    while (GET_BIT(WATCHDOG->CTL, WRC_BIT_OFFSET) == 0)
        ; // Wait for last write operation to be done
#    endif

    //  If the Watchdog is configured to trigger system resets, set the RESEN bit in the WDTCTL register.
    BITBAND_PERIREG(WATCHDOG->CTL, RESEN_BIT_OFFSET) = 1;

//  If WDT1, wait for the WRC bit in the WDTCTL register to be set.
#    if (WDT_USEDWATCHDOG == 1)
    while (GET_BIT(WATCHDOG->CTL, WRC_BIT_OFFSET) == 0)
        ; // Wait for last write operation to be done
#    endif

#    if (WDT_INTTYPE == 0)
// Do nothing
#    elif (WDT_INTTYPE == 1)
    BITBAND_PERIREG(WATCHDOG->CTL, INTTYPE_BIT_OFFSET) = WDT_INTTYPE;
#    else
#        error "Invalid WDT_INTTYPE configurations, only [0, 1] allowed."
#    endif

#    if (WDT_USEDWATCHDOG == 1)
    while (GET_BIT(WATCHDOG->CTL, WRC_BIT_OFFSET) == 0)
        ; // Wait for last write operation to be done
#    endif

#    if (isConfigEnabled(WDT_LOCKSTATUS))
    WATCHDOG->LOCK = WDT_LOCK;
#    endif

#    if (WDT_USEDWATCHDOG == 1)
    while (GET_BIT(WATCHDOG->CTL, WRC_BIT_OFFSET) == 0)
        ; // Wait for last write operation to be done
#    endif
#endif
}

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
