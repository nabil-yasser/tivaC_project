/******************************************************************************
 * @file    intCtrl.c
 *
 * @brief   Implementation of interrupts control driver that controls every
            single interrupt in arm cortex-m4.
 *
 * @version V1.0
 * @date    20 May 2024
 *
 * @author  Nabil Yasser - Embedded Software Engineer
 *
 * @author  GitHub: https://github.com/nabil-yasser
 *
 *****************************************************************************/

/* ========================================================================= */
/* ================                 INCLUDES                ================ */
/* ========================================================================= */

#include "intCtrl.h"
#include "../../config/intCtrl_cfg.h"
#include "../../utils/macros.h"

#include <stdint.h>

/* ========================================================================= */
/* ================     LOCAL MACROS CONSTANT/FUNCTIONS     ================ */
/* ========================================================================= */

#define STR(x)  #x // This macro is resolved to double quoted string ("example")
#define XSTR(s) STR(s)

#define NUMBER_OF_INTERRUPTS 78U
#define PRIGROUP_MIN         0UL
#define PRIGROUP_MAX         3UL
#define PRIGROUP_OFFSET      8UL
#define PRIGROUP_START_BIT   4UL
#define NO_PRIORITY_REGS     5UL
#define PRIORITY_BITS_OFFSET 5UL
#define ENABLE_BITS_OFFSET   5UL
#define ENABLE_BYTE_MASK     0xE0UL
#define ENABLE_BIT_MASK      0x1FUL

/* ========================================================================= */
/* ================        LOCAL FUNCTION PROTOTYPES        ================ */
/* ========================================================================= */

/******************************************************************************
 * @brief Parses the interrupt id to get mapping information from it, this
 *        function depends on masking interrupt id as following:
 *        bit (0-4) represents the bit required for making operations on this
 *        interrupt, and bit (5-7) represents the ENx register.
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Non Reentrant
 *
 * @param[in]  etInterruptId enumeration value that represents interrupt id.
 * @param[out] ui8IntRegId pointer to 8-bit varaiable that restores register id.
 * @param[out] ui32IntBitId pointer to 8-bit value that restores bit id.
 *
 * @return void
 *
 *****************************************************************************/
void static intGetMappingInfo(IRQn_Type etInterruptId, uint8_t* ui8IntRegId,
                              uint8_t* ui8IntBitId);

/******************************************************************************
 * @brief Initializes all interrupts with initial configurations made by the
 *        user in @c intCtrl_lcfg.c file.
 * 
 * Sync/Async: Synchronous
 * 
 * Reentrancy: Non Reentrant
 * 
 * @param[in] cfgArray Pointer to array of structs that carries the
 *                     configurations for each interrupt.
 * 
 * @return void
 * 
 *****************************************************************************/
void static intConfigure(intCtrl_config_st const* cfgArray);

/* ========================================================================= */
/* ================             LOCAL FUNCTIONS             ================ */
/* ========================================================================= */

void static intGetMappingInfo(IRQn_Type etInterruptId, uint8_t* ui8IntRegId,
                              uint8_t* ui8IntBitId)
{
    *ui8IntRegId  = ((etInterruptId & ENABLE_BYTE_MASK) >> ENABLE_BITS_OFFSET);
    *ui8IntBitId = (etInterruptId & ENABLE_BIT_MASK);
}

void static intConfigure(intCtrl_config_st const* cfgArray)
{
    for (uint8_t counter = 0; counter < NUMBER_OF_INTERRUPTS; counter++)
    {
        NVIC->PRI[cfgArray[counter].etInterruptId] =
            (cfgArray[counter].etPriorityLevel << PRIORITY_BITS_OFFSET);

        if (cfgArray[counter].etInterruptState == INTCTRL_ENABLE)
        {
            uint8_t  ui8IntRegister = 0;
            uint8_t  ui8IntBit     = 0;

            intGetMappingInfo(cfgArray[counter].etInterruptId, &ui8IntRegister,
                              &ui8IntBit);

            SET_BIT(NVIC->EN[ui8IntRegister], ui8IntBit); // Enables interrupt
        }
    }
}

/* ========================================================================= */
/* ================            GLOBAL FUNCTIONS             ================ */
/* ========================================================================= */

void intCtrl_init(void)
{
#if (isConfigDisabled(INTCTRL_FAULTMASK))
    __asm("CPSID f"); // This instruction disables global interrupts
#elif (isConfigEnabled(INTCTRL_FAULTMASK))
    // Nothing to do, Global interrupts are enabled by default
#else
    #error "Invalid configuration value, only [0, 1] allowed."
#endif

#if (isConfigDisabled(INTCTRL_PRIMASK))
    __asm("CPSID i"); // This instruction disables programmable interrupts
#elif (isConfigEnabled(INTCTRL_PRIMASK))
    // Nothing to do, Global interrupts are enabled by default
#else
    #error "Invalid configuration value, only [0, 1] allowed."
#endif

#if (INTCTRL_VTABLE_OFFSET) // if vtable offset is provided
    SCB->VTABLE = INTCTRL_VTABLE_OFFSET;
#endif

#if (INTCTRL_PRIGROUP >= PRIGROUP_MIN && INTCTRL_PRIGROUP <= PRIGROUP_MAX)
    SCB->APINT = 0x05FA0000
        | ((INTCTRL_PRIGROUP + PRIGROUP_START_BIT) << PRIGROUP_OFFSET);
#else
    #error "Invalid configuration value, only [0 ~ 3] allowed."
#endif

    intConfigure(g_intConfigurations);
}

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
