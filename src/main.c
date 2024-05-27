/*************************************************************************/ /**
 * @file    main.c
 *
 * @brief   This file contains the main function body
 *
 * @version V1.0
 * @date    01 May 2024
 *
 * @author  Nabil Yasser - Embedded Software Engineer
 *
 * @author  GitHub: https://github.com/nabil-yasser
 *
 *****************************************************************************/

/* ========================================================================= */
/* ================                 INCLUDES                ================ */
/* ========================================================================= */

#include "mcal/mcu/mcu.h"
#include "mcal/intCtrl/intCtrl.h"
#include "mcal/io/io.h"
#include "utils/macros.h"
#include "utils/mcu_registers.h"

/* ========================================================================= */
/* ================              MAIN FUNCTION              ================ */
/* ========================================================================= */

int main(void)
{
    // Initialization section
    mcu_init();
    intCtrl_init();
    io_init();

    // Super loop section
    for (;;)
    {
        // Program code section
    }
}

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
