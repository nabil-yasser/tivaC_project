/*************************************************************************/ /**
 * @file    mcu.h
 *
 * @brief
 *
 * @version V1.0
 * @date    25 May 2024
 *
 * @author  Nabil Yasser - Embedded Software Engineer
 *
 * @author  GitHub: https://github.com/nabil-yasser
 *
 *****************************************************************************/

#ifndef MCU_H
#    define MCU_H

/* ========================================================================= */
/* ================                 INCLUDES                ================ */
/* ========================================================================= */

/* ========================================================================= */
/* ================          GLOBAL CONSTANT MACROS         ================ */
/* ========================================================================= */

#    define PIOSC_FREQUENCY 16000000UL

/* ========================================================================= */
/* ================        GLOBAL FUNCTION PROTOTYPES       ================ */
/* ========================================================================= */

/*************************************************************************/ /**
 * @brief Initalizes the mcu based on user's configurations
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Non Reentrant
 *
 * @param void
 *
 * @return void
 *****************************************************************************/
void mcu_init(void);

#endif /* MCU_H */

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
