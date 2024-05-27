/*************************************************************************/ /**
 * @file    io_cfg.h
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

#ifndef IO_CFG_H
#    define IO_CFG_H

/* ========================================================================= */
/* ================            USER CONFIGURATIONS          ================ */
/* ========================================================================= */

/*************************************************************************/ /**
 * @brief Enable/Disable clock for GPIOA port
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define IO_USE_PORTA 1

/*************************************************************************/ /**
 * @brief Enable/Disable clock for GPIOB port
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define IO_USE_PORTB 1

/*************************************************************************/ /**
 * @brief Enable/Disable clock for GPIOC port
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define IO_USE_PORTC 1

/*************************************************************************/ /**
 * @brief Enable/Disable clock for GPIOD port
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define IO_USE_PORTD 1

/*************************************************************************/ /**
 * @brief Enable/Disable clock for GPIOE port
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define IO_USE_PORTE 1

/*************************************************************************/ /**
 * @brief Enable/Disable clock for GPIOF port
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define IO_USE_PORTF 1

/*************************************************************************/ /**
 * @brief Enable/Disable accessing PORTA via Advanced High-performance bus
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define IO_PORTA_AHB 1

/*************************************************************************/ /**
 * @brief Enable/Disable accessing PORTB via Advanced High-performance bus
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define IO_PORTB_AHB 1

/*************************************************************************/ /**
 * @brief Enable/Disable accessing PORTC via Advanced High-performance bus
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define IO_PORTC_AHB 0

/*************************************************************************/ /**
 * @brief Enable/Disable accessing PORTD via Advanced High-performance bus
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define IO_PORTD_AHB 0

/*************************************************************************/ /**
 * @brief Enable/Disable accessing PORTE via Advanced High-performance bus
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define IO_PORTE_AHB 0

/*************************************************************************/ /**
 * @brief Enable/Disable accessing PORTF via Advanced High-performance bus
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define IO_PORTF_AHB 0

#endif /* IO_CFG_H */

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
