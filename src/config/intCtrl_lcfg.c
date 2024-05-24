/******************************************************************************
 * @file    intCtrl_lcfg.c
 *
 * @brief   This file contains compile-time configurations for interrupts
 *          control driver for tm4c123gh6pm MCU.
 *
 * @version V1.0
 * @date    22 May 2024
 *
 * @author  Nabil Yasser - Embedded Software Engineer
 *
 * @author  GitHub: https://github.com/nabil-yasser
 *
 *****************************************************************************/

/* ========================================================================= */
/* ================                 INCLUDES                ================ */
/* ========================================================================= */

#include "../mcal/intCtrl/intCtrl.h"
#include "../utils/mcu_registers.h"

/* ========================================================================= */
/* ================    GLOBAL DATA TYPES AND STRUCTURES     ================ */
/* ========================================================================= */

intCtrl_config_st g_intConfigurations[] = {
  // Interrupts Configurations
    {GPIOA_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { GPIOB_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { GPIOC_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { GPIOD_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { GPIOE_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { UART0_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { UART1_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { SSI0_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { I2C0_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { PWM0_FAULT_IRQn, INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { PWM0_0_IRQn,     INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { PWM0_1_IRQn,     INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { PWM0_2_IRQn,     INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { QEI0_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { ADC0SS0_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { ADC0SS1_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { ADC0SS2_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { ADC0SS3_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WATCHDOG0_IRQn,  INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { TIMER0A_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { TIMER0B_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { TIMER1A_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { TIMER1B_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { TIMER2A_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { TIMER2B_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { COMP0_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { COMP1_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { SYSCTL_IRQn,     INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { FLASH_CTRL_IRQn, INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { GPIOF_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { UART2_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { SSI1_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { TIMER3A_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { TIMER3B_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { I2C1_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { QEI1_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { CAN0_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { CAN1_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { HIB_IRQn,        INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { USB0_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { PWM0_3_IRQn,     INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { UDMA_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { UDMAERR_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { ADC1SS0_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { ADC1SS1_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { ADC1SS2_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { ADC1SS3_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { SSI2_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { SSI3_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { UART3_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { UART4_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { UART5_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { UART6_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { UART7_IRQn,      INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { I2C2_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { I2C3_IRQn,       INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { TIMER4A_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { TIMER4B_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { TIMER5A_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { TIMER5B_IRQn,    INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WTIMER0A_IRQn,   INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WTIMER0B_IRQn,   INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WTIMER1A_IRQn,   INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WTIMER1B_IRQn,   INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WTIMER2A_IRQn,   INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WTIMER2B_IRQn,   INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WTIMER3A_IRQn,   INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WTIMER3B_IRQn,   INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WTIMER4A_IRQn,   INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WTIMER4B_IRQn,   INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WTIMER5A_IRQn,   INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { WTIMER5B_IRQn,   INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { SYSEXC_IRQn,     INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { PWM1_0_IRQn,     INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { PWM1_1_IRQn,     INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { PWM1_2_IRQn,     INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { PWM1_3_IRQn,     INTCTRL_DISABLE, XXX_GROUP0_SUB0},
    { PWM1_FAULT_IRQn, INTCTRL_DISABLE, XXX_GROUP0_SUB0},
};

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
