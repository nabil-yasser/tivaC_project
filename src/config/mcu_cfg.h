/*************************************************************************/ /**
 * @file    mcu_cfg.h
 *
 * @brief   Contains all user's configurations for mcu control driver
 *
 * @version V1.0
 * @date    25 May 2024
 *
 * @author  Nabil Yasser - Embedded Software Engineer
 *
 * @author  GitHub: https://github.com/nabil-yasser
 *
 *****************************************************************************/

#ifndef MCU_CFG_H
#    define MCU_CFG_H

/* ========================================================================= */
/* ================            USER CONFIGURATIONS          ================ */
/* ========================================================================= */

/*************************************************************************/ /**
 * @brief System oscillator source configurations
 *
 * Possible values:
 * - 0 : MOSC (Main oscillator)
 * - 1 : PIOSC (Precision internal oscillator) (default)
 * - 2 : PIOSC / 4 (Precision internal oscillator / 4)
 * - 3 : LFIOSC (Low-frequency internal oscillator)
 *****************************************************************************/
#    define MCU_OSCSRC 0

/*************************************************************************/ /**
 * @brief Enable/Disable PLL as clock source
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *****************************************************************************/
#    define MCU_PLL_STATE 0

/*************************************************************************/ /**
 * @brief Controls the value assigned to XTAL
 *
 * Possible values:
 * -  0 :  4 MHz
 * -  1 :  4.096 MHz
 * -  2 :  4.9152 MHz
 * -  3 :  5 MHz (USB)
 * -  4 :  5.12 MHz
 * -  5 :  6 MHz (USB) (default)
 * -  6 :  6.144 MHz
 * -  7 :  7.3728 MHz
 * -  8 :  8 MHz (USB)
 * -  9 :  8.192 MHz
 * - 10 :  10.0 MHz (USB)
 * - 11 :  12.0 MHz (USB)
 * - 12 :  12.288 MHz
 * - 13 :  13.56 MHz
 * - 14 :  14.31818 MHz
 * - 15 :  16.0 MHz (USB)
 * - 16 :  16.384 MHz
 * - 17 :  18.0 MHz (USB)
 * - 18 :  20.0 MHz (USB)
 * - 19 :  24.0 MHz (USB)
 * - 20 :  25.0 MHz (USB)
 *****************************************************************************/
#    define MCU_CRYSTAL_VALUE 15

/*************************************************************************/ /**
 * @brief Enable/Disable using system divisor for output clock
 *
 * Possible values:
 * - 0 : Disable (default)
 * - 1 : Enable
 *
 * @note This option must be enabled when using PLL as clock source.
 *****************************************************************************/
#    define MCU_USESYSDIV 0

/*************************************************************************/ /**
 * @brief This option configures the value used by system clock divisor
 *
 * Possible values:
 * -  0 : clk/1
 * -  1 : clk/2
 * -  2 : clk/3
 * -  3 : clk/4
 * -  4 : clk/5
 * -  5 : clk/6
 * -  6 : clk/7
 * -  7 : clk/8
 * -  8 : clk/9
 * -  9 : clk/10
 * - 10 : clk/11
 * - 11 : clk/12
 * - 12 : clk/13
 * - 13 : clk/14
 * - 14 : clk/15
 * - 15 : clk/16 (default)
 *
 * @note This option is forced when using PLL as clock source
 *****************************************************************************/
#    define MCU_SYSDIV_VALUE 15

#endif /* MCU_CFG_H */

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
