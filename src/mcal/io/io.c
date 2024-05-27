/*************************************************************************/ /**
 * @file    io.c
 *
 * @brief
 *
 * @version V1.0
 * @date    26 May 2024
 *
 * @author  Nabil Yasser - Embedded Software Engineer
 *
 * @author  GitHub: https://github.com/nabil-yasser
 *
 * @todo    Complete implementation of open-drain, GPIO digital enable control,
 *          and interrupt control.
 *
 *****************************************************************************/

/* ========================================================================= */
/* ================                 INCLUDES                ================ */
/* ========================================================================= */

#include "io.h"
#include "../../config/io_cfg.h"
#include "../../utils/macros.h"
#include "../../utils/mcu_registers.h"

#include <stdint.h>

/* ========================================================================= */
/* ================     LOCAL MACROS CONSTANT/FUNCTIONS     ================ */
/* ========================================================================= */

#if (isConfigEnabled(IO_PORTA_AHB))
#    undef GPIOA
#    define GPIOA GPIOA_AHB
#endif

#if (isConfigEnabled(IO_PORTB_AHB))
#    undef GPIOB
#    define GPIOB GPIOB_AHB
#endif

#if (isConfigEnabled(IO_PORTC_AHB))
#    undef GPIOC
#    define GPIOC GPIOC_AHB
#endif

#if (isConfigEnabled(IO_PORTD_AHB))
#    undef GPIOD
#    define GPIOD GPIOD_AHB
#endif

#if (isConfigEnabled(IO_PORTE_AHB))
#    undef GPIOE
#    define GPIOE GPIOE_AHB
#endif

#if (isConfigEnabled(IO_PORTF_AHB))
#    undef GPIOF
#    define GPIOF GPIOF_AHB
#endif

/* ========================================================================= */
/* ================     LOCAL DATA TYPES AND STRUCTURES     ================ */
/* ========================================================================= */

GPIOA_Type const* g_portRegister[IO_PORTS_COUNT] = { GPIOA, GPIOB, GPIOC,
                                                     GPIOD, GPIOE, GPIOF };

/* ========================================================================= */
/* ================    GLOBAL DATA TYPES AND STRUCTURES     ================ */
/* ========================================================================= */

extern io_pinConfig_st const g_cfgArray[];

/* ========================================================================= */
/* ================        LOCAL FUNCTION PROTOTYPES        ================ */
/* ========================================================================= */

void static getMappingInfo(io_pinId_et etPinId, uint8_t* pui8BitNumber,
                           uint8_t* pui8PortNumber);

/* ========================================================================= */
/* ================             LOCAL FUNCTIONS             ================ */
/* ========================================================================= */

void static getMappingInfo(io_pinId_et etPinId, uint8_t* pui8BitNumber,
                           uint8_t* pui8PortNumber)
{
    *pui8BitNumber = (etPinId & 0x07U); // First 3-bits represents bit number
    *pui8PortNumber =
        ((etPinId & 0x38U) >> 3U); // bits[3:5] represent port number
}

/* ========================================================================= */
/* ================            GLOBAL FUNCTIONS             ================ */
/* ========================================================================= */

void io_init(void)
{
    // Enable clock for the port in RCGCPIO register

#if (isConfigDisabled(IO_USE_PORTA) || isConfigDisabled(IO_USE_PORTB)          \
     || isConfigDisabled(IO_USE_PORTC) || isConfigDisabled(IO_USE_PORTD)       \
     || isConfigDisabled(IO_USE_PORTE) || isConfigDisabled(IO_USE_PORTF))
    // Do nothing

#elif (isConfigEnabled(IO_USE_PORTA) || isConfigEnabled(IO_USE_PORTB)          \
       || isConfigEnabled(IO_USE_PORTC) || isConfigEnabled(IO_USE_PORTD)       \
       || isConfigEnabled(IO_USE_PORTE) || isConfigEnabled(IO_USE_PORTF))
    SYSCTL->RCGCGPIO = ((1 << IO_PORTA) | (1 << IO_PORTB) | (1 << IO_PORTC)
                        | (1 << IO_PORTD) | (1 << IO_PORTE) | (1 << IO_PORTF));
#endif

    uint8_t ui8BitId  = 0;
    uint8_t ui8PortId = 0;

    for (uint8_t count = 0; count < IO_PINS_COUNT; count++)
    {
        getMappingInfo(g_cfgArray[count].etPinId, &ui8BitId, &ui8PortId);

        // Setting the direction for the pin
        BITBAND_PERIREG(g_portRegister[ui8PortId]->DIR, ui8BitId) =
            g_cfgArray[count].etPinDirection;

        // Setting alternative function for each pin
        if (g_cfgArray[count].etAltFunction != IO_GPIO_FUNCTION)
        {
            // Enables alternative function for this specific bit
            BITBAND_PERIREG(g_portRegister[ui8PortId]->AFSEL, ui8BitId) = 1UL;

            /* Assigns the user configured value for alternative function
                into PCTL register for this specific bit */
            BITBAND_PERIREG(g_portRegister[ui8PortId]->PCTL, ui8BitId) =
                (g_cfgArray[count].etAltFunction << (ui8BitId * 4U));
        }

        // Setting the current drive strnegth for each pin
        if (g_cfgArray[count].etDriveCurrent == IO_DRIVE_2MA)
        {
            BITBAND_PERIREG(g_portRegister[ui8PortId]->DR2R, ui8BitId) = 1;
        }
        else if (g_cfgArray[count].etDriveCurrent == IO_DRIVE_4MA)
        {
            BITBAND_PERIREG(g_portRegister[ui8PortId]->DR4R, ui8BitId) = 1;
        }
        else if (g_cfgArray[count].etDriveCurrent == IO_DRIVE_8MA)
        {
            BITBAND_PERIREG(g_portRegister[ui8PortId]->DR8R, ui8BitId) = 1;
        }
        else
        {
            // Nothing to do
        }

        // Setting the resistor type for each pin
        if (g_cfgArray[count].etResistorType == IO_RES_PDR)
        {
            BITBAND_PERIREG(g_portRegister[ui8PortId]->PDR, ui8BitId) = 1;
        }
        else if (g_cfgArray[count].etDriveCurrent == IO_RES_PUR)
        {
            BITBAND_PERIREG(g_portRegister[ui8PortId]->PUR, ui8BitId) = 1;
        }
        else
        {
            // Nothing to do
        }

        // Setting the level of each type
        BITBAND_PERIREG(g_portRegister[ui8PortId]->DATA, ui8BitId) =
            g_cfgArray[count].etInitialPinLevel;
    }
}

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
