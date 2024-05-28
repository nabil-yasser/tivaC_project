/*************************************************************************/ /**
 * @file    wdt_cfg.h
 * 
 * @brief   Contains user's configurations for watchdog timer 1
 * 
 * @version V1.0
 * @date    28 May 2024
 * 
 * @author  Nabil Yasser - Embedded Software Engineer
 * 
 * @author  GitHub: https://github.com/nabil-yasser
 * 
 *****************************************************************************/

#ifndef WDT_CFG_H
#    define WDT_CFG_H

/* ========================================================================= */
/* ================            USER CONFIGURATIONS          ================ */
/* ========================================================================= */

/*************************************************************************/ /**
 * @brief Disable/Enable watchdog timer
 *
 * Possible values:
 * - 0 : Disable Watchdog timer (default)
 * - 1 : Enable Watchdog timer
 *****************************************************************************/
#    define WDT_STATUS 1

/*************************************************************************/ /**
 * @brief This option configures which watchdog timer is used for your system
 *
 * Possible values:
 * - 0 : Watchdog timer 0 (default)
 * - 1 : Watchdog timer 1
 *****************************************************************************/
#    define WDT_USEDWATCHDOG 1

/*************************************************************************/ /**
 * @brief Provides the value to be loaded into the watchdog timer
 *
 * Possible values:
 * - A 16-bit value representing time in milliseconds
 * 
 * @note The time should be only in milliseconds in order to work properly
 * 
 * @warning This option only applied when using WDT1, for WDT0 you must go
 *          to @c wdt.c file and edit the @c loadValue() value manually
 *          depending on the system frequency you use.
 *****************************************************************************/
#    define WDT_LOADVALUE 500

/*************************************************************************/ /**
 * @brief Configures whether to assert reset or not after WDT timeout
 *
 * Possible values:
 * - 0 : Disable WDT reset output (default)
 * - 1 : Enable WDT reset output
 *****************************************************************************/
#    define WDT_RESEN 1

/*************************************************************************/ /**
 * @brief Configures watchdog timer interrupt type
 *
 * Possible values:
 * - 0 : Watchdog interrupt is a standard interrupt (default)
 * - 1 : Watchdog interrupt is a non-maskable interrupt
 *****************************************************************************/
#    define WDT_INTTYPE 1

/*************************************************************************/ /**
 * @brief Disable/Enable locking WDT registers after initialization
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define WDT_LOCKSTATUS 1

#endif /* WDT_CFG_H */

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
