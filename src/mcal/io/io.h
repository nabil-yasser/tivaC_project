/*************************************************************************/ /**
 * @file    io.h
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

#ifndef IO_H
#    define IO_H

/* ========================================================================= */
/* ================                 INCLUDES                ================ */
/* ========================================================================= */

/* ========================================================================= */
/* ================          GLOBAL CONSTANT MACROS         ================ */
/* ========================================================================= */

typedef enum
{
    IO_LOW,  ///< Digital low level
    IO_HIGH, ///< Digital high level
} io_pinLevel_et;

typedef enum
{
    IO_INPUT,  ///< Input channel
    IO_OUTPUT, ///< Output channel
} io_pinDirection_et;

typedef enum
{
    IO_PORTA,       ///< PORTA block
    IO_PORTB,       ///< PORTB block
    IO_PORTC,       ///< PORTC block
    IO_PORTD,       ///< PORTD block
    IO_PORTE,       ///< PORTE block
    IO_PORTF,       ///< PORTF block
    IO_PORTS_COUNT, ///< Number of ports
} io_portId_et;

typedef enum
{
    IO_PINA0, ///< Pin 0 @ PORTA
    IO_PINA1, ///< Pin 1 @ PORTA
    IO_PINA2, ///< Pin 2 @ PORTA
    IO_PINA3, ///< Pin 3 @ PORTA
    IO_PINA4, ///< Pin 4 @ PORTA
    IO_PINA5, ///< Pin 5 @ PORTA
    IO_PINA6, ///< Pin 6 @ PORTA
    IO_PINA7, ///< Pin 7 @ PORTA

    IO_PINB0, ///< Pin 0 @ PORTB
    IO_PINB1, ///< Pin 1 @ PORTB
    IO_PINB2, ///< Pin 2 @ PORTB
    IO_PINB3, ///< Pin 3 @ PORTB
    IO_PINB4, ///< Pin 4 @ PORTB
    IO_PINB5, ///< Pin 5 @ PORTB
    IO_PINB6, ///< Pin 6 @ PORTB
    IO_PINB7, ///< Pin 7 @ PORTB

    IO_PINC0, ///< Pin 0 @ PORTC
    IO_PINC1, ///< Pin 1 @ PORTC
    IO_PINC2, ///< Pin 2 @ PORTC
    IO_PINC3, ///< Pin 3 @ PORTC
    IO_PINC4, ///< Pin 4 @ PORTC
    IO_PINC5, ///< Pin 5 @ PORTC
    IO_PINC6, ///< Pin 6 @ PORTC
    IO_PINC7, ///< Pin 7 @ PORTC

    IO_PIND0, ///< Pin 0 @ PORTD
    IO_PIND1, ///< Pin 1 @ PORTD
    IO_PIND2, ///< Pin 2 @ PORTD
    IO_PIND3, ///< Pin 3 @ PORTD
    IO_PIND4, ///< Pin 4 @ PORTD
    IO_PIND5, ///< Pin 5 @ PORTD
    IO_PIND6, ///< Pin 6 @ PORTD
    IO_PIND7, ///< Pin 7 @ PORTD

    IO_PINE0, ///< Pin 0 @ PORTE
    IO_PINE1, ///< Pin 1 @ PORTE
    IO_PINE2, ///< Pin 2 @ PORTE
    IO_PINE3, ///< Pin 3 @ PORTE
    IO_PINE4, ///< Pin 4 @ PORTE
    IO_PINE5, ///< Pin 5 @ PORTE

    IO_PINF0 = 40, /*!< Pin 0 @ PORTF
                      NOTE: Changed the value because PORTE is only 6-bits) */
    IO_PINF1,      ///< Pin 1 @ PORTF
    IO_PINF2,      ///< Pin 2 @ PORTF
    IO_PINF3,      ///< Pin 3 @ PORTF
    IO_PINF4,      ///< Pin 4 @ PORTF

    IO_PINS_COUNT = 43, ///< Number of pins
} io_pinId_et;

typedef enum
{
    IO_DRIVE_2MA, ///< Drive current strength 2mA
    IO_DRIVE_4MA, ///< Drive current strength 4mA
    IO_DRIVE_8MA, ///< Drive current strength 8mA
} io_driveCurrent_et;

typedef enum
{
    IO_RES_DISABLED, ///< Internal resistor is disabled
    IO_RES_PDR,      ///< Internal pull-down resistor
    IO_RES_PUR,      ///< Internal pull-up resistor
} io_resistor_et;

typedef enum
{
    IO_GPIO_FUNCTION = 0,  ///< Pin works as GPIO
    IO_PA0_CAN1Rx    = 8,  ///< Pin works as CAN1Rx
    IO_PA0_U0Rx      = 1,  ///< Pin works as U0Rx
    IO_PA1_CAN1Tx    = 8,  ///< Pin works as CAN1Tx
    IO_PA1_U0Tx      = 1,  ///< Pin works as U0Tx
    IO_PA2_SSI0Clk   = 2,  ///< Pin works as SSI0Clk
    IO_PA3_SSI0Fss   = 2,  ///< Pin works as SSI0Fss
    IO_PA4_SSI0Rx    = 2,  ///< Pin works as SSI0Rx
    IO_PA5_SSI0Tx    = 2,  ///< Pin works as SSI0Tx
    IO_PA6_I2C1SCL   = 3,  ///< Pin works as I2C1SCL
    IO_PA6_M1PWM2    = 5,  ///< Pin works as M1PWM2
    IO_PA7_I2C1SDA   = 3,  ///< Pin works as I2C1SDA
    IO_PA7_M1PWM3    = 5,  ///< Pin works as M1PWM3
    IO_PB0_T2CCP0    = 7,  ///< Pin works as T2CCP0
    IO_PB0_U1Rx      = 1,  ///< Pin works as U1Rx
    IO_PB1_T2CCP1    = 7,  ///< Pin works as T2CCP1
    IO_PB1_U1Tx      = 1,  ///< Pin works as U1Tx
    IO_PB2_I2C0SCL   = 3,  ///< Pin works as I2C0SCL
    IO_PB2_T3CCP0    = 7,  ///< Pin works as T3CCP0
    IO_PB3_I2C0SDA   = 3,  ///< Pin works as I2C0SDA
    IO_PB3_T3CCP1    = 7,  ///< Pin works as T3CCP1
    IO_PB4_CAN0Rx    = 8,  ///< Pin works as CAN0Rx
    IO_PB4_M0PWM2    = 4,  ///< Pin works as M0PWM2
    IO_PB4_SSI2Clk   = 2,  ///< Pin works as SSI2Clk
    IO_PB4_T1CCP0    = 7,  ///< Pin works as T1CCP0
    IO_PB5_CAN0Tx    = 8,  ///< Pin works as CAN0Tx
    IO_PB5_M0PWM3    = 4,  ///< Pin works as M0PWM3
    IO_PB5_SSI2Fss   = 2,  ///< Pin works as SSI2Fss
    IO_PB5_T1CCP1    = 7,  ///< Pin works as T1CCP1
    IO_PB6_M0PWM0    = 4,  ///< Pin works as M0PWM0
    IO_PB6_SSI2Rx    = 2,  ///< Pin works as SSI2Rx
    IO_PB6_T0CCP0    = 7,  ///< Pin works as T0CCP0
    IO_PB7_M0PWM1    = 4,  ///< Pin works as M0PWM1
    IO_PB7_SSI2Tx    = 2,  ///< Pin works as SSI2Tx
    IO_PB7_T0CCP1    = 7,  ///< Pin works as T0CCP1
    IO_PC0_SWCLK     = 2,  ///< Pin works as SWCLK
    IO_PC0_T4CCP0    = 8,  ///< Pin works as T4CCP0
    IO_PC0_TCK       = 1,  ///< Pin works as TCK
    IO_PC1_SWDIO     = 2,  ///< Pin works as SWDIO
    IO_PC1_T4CCP1    = 8,  ///< Pin works as T4CCP1
    IO_PC1_TMS       = 1,  ///< Pin works as TMS
    IO_PC2_T5CCP0    = 7,  ///< Pin works as T5CCP0
    IO_PC2_TDI       = 1,  ///< Pin works as TDI
    IO_PC3_SWO       = 2,  ///< Pin works as SWO
    IO_PC3_T5CCP1    = 8,  ///< Pin works as T5CCP1
    IO_PC3_TDO       = 1,  ///< Pin works as TDO
    IO_PC4_IDX1      = 6,  ///< Pin works as IDX1
    IO_PC4_M0PWM6    = 4,  ///< Pin works as M0PWM6
    IO_PC4_U1RTS     = 8,  ///< Pin works as U1RTS
    IO_PC4_U1Rx      = 2,  ///< Pin works as U1Rx
    IO_PC4_U4Rx      = 1,  ///< Pin works as U4Rx
    IO_PC4_WT0CCP0   = 7,  ///< Pin works as WT0CCP0
    IO_PC5_M0PWM7    = 4,  ///< Pin works as M0PWM7
    IO_PC5_PhA1      = 6,  ///< Pin works as PhA1
    IO_PC5_U1CTS     = 8,  ///< Pin works as U1CTS
    IO_PC5_U1Tx      = 2,  ///< Pin works as U1Tx
    IO_PC5_U4Tx      = 1,  ///< Pin works as U4Tx
    IO_PC5_WT0CCP1   = 7,  ///< Pin works as WT0CCP1
    IO_PC6_PhB1      = 6,  ///< Pin works as PhB1
    IO_PC6_U3Rx      = 1,  ///< Pin works as U3Rx
    IO_PC6_USB0EPEN  = 8,  ///< Pin works as USB0EPEN
    IO_PC6_WT1CCP0   = 7,  ///< Pin works as WT1CCP0
    IO_PC7_U3Tx      = 1,  ///< Pin works as U3Tx
    IO_PC7_USB0PFLT  = 8,  ///< Pin works as USB0PFLT
    IO_PC7_WT1CCP1   = 7,  ///< Pin works as WT1CCP1
    IO_PD0_I2C3SCL   = 3,  ///< Pin works as I2C3SCL
    IO_PD0_M0PWM6    = 4,  ///< Pin works as M0PWM6
    IO_PD0_M1PWM0    = 5,  ///< Pin works as M1PWM0
    IO_PD0_SSI1Clk   = 2,  ///< Pin works as SSI1Clk
    IO_PD0_SSI3Clk   = 1,  ///< Pin works as SSI3Clk
    IO_PD0_WT2CCP0   = 7,  ///< Pin works as WT2CCP0
    IO_PD1_I2C3SDA   = 3,  ///< Pin works as I2C3SDA
    IO_PD1_M0PWM7    = 4,  ///< Pin works as M0PWM7
    IO_PD1_M1PWM1    = 5,  ///< Pin works as M1PWM1
    IO_PD1_SSI1Fss   = 2,  ///< Pin works as SSI1Fss
    IO_PD1_SSI3Fss   = 1,  ///< Pin works as SSI3Fss
    IO_PD1_WT2CCP1   = 7,  ///< Pin works as WT2CCP1
    IO_PD2_M0FAULT0  = 4,  ///< Pin works as M0FAULT0
    IO_PD2_SSI1Rx    = 2,  ///< Pin works as SSI1Rx
    IO_PD2_SSI3Rx    = 1,  ///< Pin works as SSI3Rx
    IO_PD2_USB0EPEN  = 8,  ///< Pin works as USB0EPEN
    IO_PD2_WT3CCP0   = 7,  ///< Pin works as WT3CCP0
    IO_PD3_IDX0      = 6,  ///< Pin works as IDX0
    IO_PD3_SSI1Tx    = 2,  ///< Pin works as SSI1Tx
    IO_PD3_SSI3Tx    = 1,  ///< Pin works as SSI3Tx
    IO_PD3_USB0PFLT  = 8,  ///< Pin works as USB0PFLT
    IO_PD3_WT3CCP1   = 7,  ///< Pin works as WT3CCP1
    IO_PD4_U6Rx      = 1,  ///< Pin works as U6Rx
    IO_PD4_WT4CCP0   = 7,  ///< Pin works as WT4CCP0
    IO_PD5_U6Tx      = 1,  ///< Pin works as U6Tx
    IO_PD5_WT4CCP1   = 7,  ///< Pin works as WT4CCP1
    IO_PD6_M0FAULT0  = 4,  ///< Pin works as M0FAULT0
    IO_PD6_PhA0      = 6,  ///< Pin works as PhA0
    IO_PD6_U2Rx      = 1,  ///< Pin works as U2Rx
    IO_PD6_WT5CCP0   = 7,  ///< Pin works as WT5CCP0
    IO_PD7_NMI       = 8,  ///< Pin works as NMI
    IO_PD7_PhB0      = 6,  ///< Pin works as PhB0
    IO_PD7_U2Tx      = 1,  ///< Pin works as U2Tx
    IO_PD7_WT5CCP1   = 7,  ///< Pin works as WT5CCP1
    IO_PE0_U7Rx      = 1,  ///< Pin works as U7Rx
    IO_PE1_U7Tx      = 1,  ///< Pin works as U7Tx
    IO_PE4_CAN0Rx    = 8,  ///< Pin works as CAN0Rx
    IO_PE4_I2C2SCL   = 3,  ///< Pin works as I2C2SCL
    IO_PE4_M0PWM4    = 4,  ///< Pin works as M0PWM4
    IO_PE4_M1PWM2    = 5,  ///< Pin works as M1PWM2
    IO_PE4_U5Rx      = 1,  ///< Pin works as U5Rx
    IO_PE5_CAN0Tx    = 8,  ///< Pin works as CAN0Tx
    IO_PE5_I2C2SDA   = 3,  ///< Pin works as I2C2SDA
    IO_PE5_M0PWM5    = 4,  ///< Pin works as M0PWM5
    IO_PE5_M1PWM3    = 5,  ///< Pin works as M1PWM3
    IO_PE5_U5Tx      = 1,  ///< Pin works as U5Tx
    IO_PF0_C0o       = 9,  ///< Pin works as C0o
    IO_PF0_CAN0Rx    = 3,  ///< Pin works as CAN0Rx
    IO_PF0_M1PWM4    = 5,  ///< Pin works as M1PWM4
    IO_PF0_NMI       = 8,  ///< Pin works as NMI
    IO_PF0_PhA0      = 6,  ///< Pin works as PhA0
    IO_PF0_SSI1Rx    = 2,  ///< Pin works as SSI1Rx
    IO_PF0_T0CCP0    = 7,  ///< Pin works as T0CCP0
    IO_PF0_U1RTS     = 1,  ///< Pin works as U1RTS
    IO_PF1_C1o       = 9,  ///< Pin works as C1o
    IO_PF1_M1PWM5    = 5,  ///< Pin works as M1PWM5
    IO_PF1_PhB0      = 6,  ///< Pin works as PhB0
    IO_PF1_SSI1Tx    = 2,  ///< Pin works as SSI1Tx
    IO_PF1_T0CCP1    = 7,  ///< Pin works as T0CCP1
    IO_PF1_TRD1      = 14, ///< Pin works as TRD1
    IO_PF1_U1CTS     = 1,  ///< Pin works as U1CTS
    IO_PF2_M0FAULT0  = 4,  ///< Pin works as M0FAULT0
    IO_PF2_M1PWM6    = 5,  ///< Pin works as M1PWM6
    IO_PF2_SSI1Clk   = 2,  ///< Pin works as SSI1Clk
    IO_PF2_T1CCP0    = 7,  ///< Pin works as T1CCP0
    IO_PF2_TRD0      = 14, ///< Pin works as TRD0
    IO_PF3_CAN0Tx    = 3,  ///< Pin works as CAN0Tx
    IO_PF3_M1PWM7    = 5,  ///< Pin works as M1PWM7
    IO_PF3_SSI1Fss   = 2,  ///< Pin works as SSI1Fss
    IO_PF3_T1CCP1    = 7,  ///< Pin works as T1CCP1
    IO_PF3_TRCLK     = 14, ///< Pin works as TRCLK
    IO_PF4_IDX0      = 6,  ///< Pin works as IDX0
    IO_PF4_M1FAULT0  = 5,  ///< Pin works as M1FAULT0
    IO_PF4_T2CCP0    = 7,  ///< Pin works as T2CCP0
    IO_PF4_USB0EPEN  = 8,  ///< Pin works as USB0EPEN
} io_pinAlt_et;

typedef struct
{
    io_pinId_et        etPinId;
    io_pinDirection_et etPinDirection;
    io_pinLevel_et     etInitialPinLevel;
    io_driveCurrent_et etDriveCurrent;
    io_resistor_et     etResistorType;
    io_pinAlt_et       etAltFunction;
} io_pinConfig_st;

/* <---------------------[ NVIC Peripheral Addresses ]---------------------> */

/* ========================================================================= */
/* ================          GLOBAL FUNCTION MACROS         ================ */
/* ========================================================================= */

/* ========================================================================= */
/* ================     GLOBAL DATA TYPES AND STRUCTURES    ================ */
/* ========================================================================= */

/* ========================================================================= */
/* ================          GLOBAL DATA PROTOTYPES         ================ */
/* ========================================================================= */

/* ========================================================================= */
/* ================        GLOBAL FUNCTION PROTOTYPES       ================ */
/* ========================================================================= */

/*************************************************************************/ /**
 * @brief Initializes the GPIO peripheral depending on user's configurations
 *
 * Sync/Async: Synchronous
 *
 * Reentrancy: Non Reentrant
 *
 *****************************************************************************/
void io_init(void);

#endif /* IO_H */

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
