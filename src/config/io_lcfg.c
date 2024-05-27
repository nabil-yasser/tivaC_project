/******************************************************************************
 * @file    io_lcfg.c
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
 *****************************************************************************/

/* ========================================================================= */
/* ================                 INCLUDES                ================ */
/* ========================================================================= */

#include "../mcal/io/io.h"

/* ========================================================================= */
/* ================     LOCAL MACROS CONSTANT/FUNCTIONS     ================ */
/* ========================================================================= */

/* ========================================================================= */
/* ================     LOCAL DATA TYPES AND STRUCTURES     ================ */
/* ========================================================================= */

/* ========================================================================= */
/* ================    GLOBAL DATA TYPES AND STRUCTURES     ================ */
/* ========================================================================= */

io_pinConfig_st const g_cfgArray[IO_PINS_COUNT] = {
    {IO_PINA0,  IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINA1, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINA2, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINA3, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINA4, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINA5, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINA6, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINA7, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINB0, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINB1, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINB2, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINB3, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINB4, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINB5, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINB6, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINB7, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINC0, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINC1, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINC2, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINC3, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINC4, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINC5, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINC6, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINC7, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PIND0, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PIND1, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PIND2, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PIND3, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PIND4, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PIND5, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PIND6, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PIND7, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINE0, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINE1, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINE2, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINE3, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINE4, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINE5, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINF0, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINF1, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINF2, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINF3, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
    { IO_PINF4, IO_OUTPUT, IO_HIGH, IO_DRIVE_8MA, IO_RES_PDR,
     IO_GPIO_FUNCTION},
};

/* ========================================================================= */
/* ================        LOCAL FUNCTION PROTOTYPES        ================ */
/* ========================================================================= */

/* ========================================================================= */
/* ================             LOCAL FUNCTIONS             ================ */
/* ========================================================================= */

/* ========================================================================= */
/* ================            GLOBAL FUNCTIONS             ================ */
/* ========================================================================= */

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
