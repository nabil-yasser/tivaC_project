/******************************************************************************
 * @file    mcu_registers.h
 *
 * @date    11 Feb 2024
 *
 * @author  Nabil Yasser - Embedded Software Engineer
 *
 * @author  GitHub: https://github.com/nabil-yasser
 *
 * @brief   Includes ATmega16A memory mapped registers and interrupt vectors
 *
 *****************************************************************************/

#ifndef MCU_REGISTERS_H
#define MCU_REGISTERS_H

/* ========================================================================= */
/* ================          GLOBAL CONSTANT MACROS         ================ */
/* ========================================================================= */

#define ADDRESS_OFFSET          0x20
#define _REG8_PROVIDE(address)  (*(volatile uint8 *)(address + ADDRESS_OFFSET))
#define _REG16_PROVIDE(address) (*(volatile uint16 *)(address + ADDRESS_OFFSET))

#define ISR(INT_vect)                                                          \
    void INT_vect(void) __attribute__((signal, used));                         \
    void INT_vect(void)

/* ========================================================================= */
/* ================        MICROCONTROLLER REGISTERS        ================ */
/* ========================================================================= */

#define TWBR    _REG8_PROVIDE(0x00)
#define TWBR0   0
#define TWBR1   1
#define TWBR2   2
#define TWBR3   3
#define TWBR4   4
#define TWBR5   5
#define TWBR6   6
#define TWBR7   7

#define TWSR    _REG8_PROVIDE(0x01)
#define TWPS0   0
#define TWPS1   1
#define TWS3    3
#define TWS4    4
#define TWS5    5
#define TWS6    6
#define TWS7    7

#define TWAR    _REG8_PROVIDE(0x02)
#define TWGCE   0
#define TWA0    1
#define TWA1    2
#define TWA2    3
#define TWA3    4
#define TWA4    5
#define TWA5    6
#define TWA6    7

#define TWDR    _REG8_PROVIDE(0x03)
#define TWD0    0
#define TWD1    1
#define TWD2    2
#define TWD3    3
#define TWD4    4
#define TWD5    5
#define TWD6    6
#define TWD7    7

#define ADCL    _REG8_PROVIDE(0x04)
#define ADCL0   0
#define ADCL1   1
#define ADCL2   2
#define ADCL3   3
#define ADCL4   4
#define ADCL5   5
#define ADCL6   6
#define ADCL7   7

#define ADCH    _REG8_PROVIDE(0x05)
#define ADCH0   0
#define ADCH1   1
#define ADCH2   2
#define ADCH3   3
#define ADCH4   4
#define ADCH5   5
#define ADCH6   6
#define ADCH7   7

#define ADCSRA  _REG8_PROVIDE(0x06)
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ADMUX   _REG8_PROVIDE(0x07)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define ADLAR   5
#define REFS0   6
#define REFS1   7

#define ACSR    _REG8_PROVIDE(0x08)
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACBG    6
#define ACD     7

#define UBRRL   _REG8_PROVIDE(0x09)
#define UBRR0   0
#define UBRR1   1
#define UBRR2   2
#define UBRR3   3
#define UBRR4   4
#define UBRR5   5
#define UBRR6   6
#define UBRR7   7

#define UCSRB   _REG8_PROVIDE(0x0A)
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

#define UCSRA   _REG8_PROVIDE(0x0B)
#define MPCM    0
#define U2X     1
#define UPE     2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7

#define UDR     _REG8_PROVIDE(0x0C)
#define UDR0    0
#define UDR1    1
#define UDR2    2
#define UDR3    3
#define UDR4    4
#define UDR5    5
#define UDR6    6
#define UDR7    7

#define SPCR    _REG8_PROVIDE(0x0D)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define SPSR    _REG8_PROVIDE(0x0E)
#define SPI2X   0
#define WCOL    6
#define SPIF    7

#define SPDR    _REG8_PROVIDE(0x0F)
#define SPDR0   0
#define SPDR1   1
#define SPDR2   2
#define SPDR3   3
#define SPDR4   4
#define SPDR5   5
#define SPDR6   6
#define SPDR7   7

#define PIND    _REG8_PROVIDE(0x10)
#define PIND0   0
#define PIND1   1
#define PIND2   2
#define PIND3   3
#define PIND4   4
#define PIND5   5
#define PIND6   6
#define PIND7   7

#define DDRD    _REG8_PROVIDE(0x11)
#define DDD0    0
#define DDD1    1
#define DDD2    2
#define DDD3    3
#define DDD4    4
#define DDD5    5
#define DDD6    6
#define DDD7    7

#define PORTD   _REG8_PROVIDE(0x12)
#define PORTD0  0
#define PORTD1  1
#define PORTD2  2
#define PORTD3  3
#define PORTD4  4
#define PORTD5  5
#define PORTD6  6
#define PORTD7  7

#define PINC    _REG8_PROVIDE(0x13)
#define PINC0   0
#define PINC1   1
#define PINC2   2
#define PINC3   3
#define PINC4   4
#define PINC5   5
#define PINC6   6
#define PINC7   7

#define DDRC    _REG8_PROVIDE(0x14)
#define DDC0    0
#define DDC1    1
#define DDC2    2
#define DDC3    3
#define DDC4    4
#define DDC5    5
#define DDC6    6
#define DDC7    7

#define PORTC   _REG8_PROVIDE(0x15)
#define PORTC0  0
#define PORTC1  1
#define PORTC2  2
#define PORTC3  3
#define PORTC4  4
#define PORTC5  5
#define PORTC6  6
#define PORTC7  7

#define PINB    _REG8_PROVIDE(0x16)
#define PINB0   0
#define PINB1   1
#define PINB2   2
#define PINB3   3
#define PINB4   4
#define PINB5   5
#define PINB6   6
#define PINB7   7

#define DDRB    _REG8_PROVIDE(0x17)
#define DDB0    0
#define DDB1    1
#define DDB2    2
#define DDB3    3
#define DDB4    4
#define DDB5    5
#define DDB6    6
#define DDB7    7

#define PORTB   _REG8_PROVIDE(0x18)
#define PORTB0  0
#define PORTB1  1
#define PORTB2  2
#define PORTB3  3
#define PORTB4  4
#define PORTB5  5
#define PORTB6  6
#define PORTB7  7

#define PINA    _REG8_PROVIDE(0x19)
#define PINA0   0
#define PINA1   1
#define PINA2   2
#define PINA3   3
#define PINA4   4
#define PINA5   5
#define PINA6   6
#define PINA7   7

#define DDRA    _REG8_PROVIDE(0x1A)
#define DDA0    0
#define DDA1    1
#define DDA2    2
#define DDA3    3
#define DDA4    4
#define DDA5    5
#define DDA6    6
#define DDA7    7

#define PORTA   _REG8_PROVIDE(0x1B)
#define PORTA0  0
#define PORTA1  1
#define PORTA2  2
#define PORTA3  3
#define PORTA4  4
#define PORTA5  5
#define PORTA6  6
#define PORTA7  7

#define EECR    _REG8_PROVIDE(0x1C)
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3

#define EEDR    _REG8_PROVIDE(0x1D)
#define EEDR0   0
#define EEDR1   1
#define EEDR2   2
#define EEDR3   3
#define EEDR4   4
#define EEDR5   5
#define EEDR6   6
#define EEDR7   7

#define EEAR    _REG16_PROVIDE(0x1E)

#define EEARL   _REG8_PROVIDE(0x1E)
#define EEAR0   0
#define EEAR1   1
#define EEAR2   2
#define EEAR3   3
#define EEAR4   4
#define EEAR5   5
#define EEAR6   6
#define EEAR7   7

#define EEARH   _REG8_PROVIDE(0x1F)
#define EEAR8   0

#define UBRRH   _REG8_PROVIDE(0x20)
#define UBRR8   0
#define UBRR9   1
#define UBRR10  2
#define UBRR11  3

#define UCSRC   _REG8_PROVIDE(0x20)
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL   6
#define URSEL   7

#define WDTCR   _REG8_PROVIDE(0x21)
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDE     3
#define WDTOE   4

#define ASSR    _REG8_PROVIDE(0x22)
#define TCR2UB  0
#define OCR2UB  1
#define TCN2UB  2
#define AS2     3

#define OCR2    _REG8_PROVIDE(0x23)
#define OCR2_0  0
#define OCR2_1  1
#define OCR2_2  2
#define OCR2_3  3
#define OCR2_4  4
#define OCR2_5  5
#define OCR2_6  6
#define OCR2_7  7

#define TCNT2   _REG8_PROVIDE(0x24)
#define TCNT2_0 0
#define TCNT2_1 1
#define TCNT2_2 2
#define TCNT2_3 3
#define TCNT2_4 4
#define TCNT2_5 5
#define TCNT2_6 6
#define TCNT2_7 7

#define TCCR2   _REG8_PROVIDE(0x25)
#define CS20    0
#define CS21    1
#define CS22    2
#define WGM21   3
#define COM20   4
#define COM21   5
#define WGM20   6
#define FOC2    7

#define ICR1    _REG16_PROVIDE(0x26)

#define ICR1L   _REG8_PROVIDE(0x26)
#define ICR1L0  0
#define ICR1L1  1
#define ICR1L2  2
#define ICR1L3  3
#define ICR1L4  4
#define ICR1L5  5
#define ICR1L6  6
#define ICR1L7  7

#define ICR1H   _REG8_PROVIDE(0x27)
#define ICR1H0  0
#define ICR1H1  1
#define ICR1H2  2
#define ICR1H3  3
#define ICR1H4  4
#define ICR1H5  5
#define ICR1H6  6
#define ICR1H7  7

#define OCR1B   _REG16_PROVIDE(0x28)

#define OCR1BL  _REG8_PROVIDE(0x28)
#define OCR1BL0 0
#define OCR1BL1 1
#define OCR1BL2 2
#define OCR1BL3 3
#define OCR1BL4 4
#define OCR1BL5 5
#define OCR1BL6 6
#define OCR1BL7 7

#define OCR1BH  _REG8_PROVIDE(0x29)
#define OCR1BH0 0
#define OCR1BH1 1
#define OCR1BH2 2
#define OCR1BH3 3
#define OCR1BH4 4
#define OCR1BH5 5
#define OCR1BH6 6
#define OCR1BH7 7

#define OCR1A   _REG16_PROVIDE(0x2A)

#define OCR1AL  _REG8_PROVIDE(0x2A)
#define OCR1AL0 0
#define OCR1AL1 1
#define OCR1AL2 2
#define OCR1AL3 3
#define OCR1AL4 4
#define OCR1AL5 5
#define OCR1AL6 6
#define OCR1AL7 7

#define OCR1AH  _REG8_PROVIDE(0x2B)
#define OCR1AH0 0
#define OCR1AH1 1
#define OCR1AH2 2
#define OCR1AH3 3
#define OCR1AH4 4
#define OCR1AH5 5
#define OCR1AH6 6
#define OCR1AH7 7

#define TCNT1   _REG16_PROVIDE(0x2C)

#define TCNT1L  _REG8_PROVIDE(0x2C)
#define TCNT1L0 0
#define TCNT1L1 1
#define TCNT1L2 2
#define TCNT1L3 3
#define TCNT1L4 4
#define TCNT1L5 5
#define TCNT1L6 6
#define TCNT1L7 7

#define TCNT1H  _REG8_PROVIDE(0x2D)
#define TCNT1H0 0
#define TCNT1H1 1
#define TCNT1H2 2
#define TCNT1H3 3
#define TCNT1H4 4
#define TCNT1H5 5
#define TCNT1H6 6
#define TCNT1H7 7

#define TCCR1B  _REG8_PROVIDE(0x2E)
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define TCCR1A  _REG8_PROVIDE(0x2F)
#define WGM10   0
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define SFIOR   _REG8_PROVIDE(0x30)
#define PSR10   0
#define PSR2    1
#define PUD     2
#define ACME    3
#define ADTS0   5
#define ADTS1   6
#define ADTS2   7

#define OSCCAL  _REG8_PROVIDE(0x31)
#define CAL0    0
#define CAL1    1
#define CAL2    2
#define CAL3    3
#define CAL4    4
#define CAL5    5
#define CAL6    6
#define CAL7    7

#define OCDR    _REG8_PROVIDE(0x31)
#define OCDR0   0
#define OCDR1   1
#define OCDR2   2
#define OCDR3   3
#define OCDR4   4
#define OCDR5   5
#define OCDR6   6
#define OCDR7   7

#define TCNT0   _REG8_PROVIDE(0x32)
#define TCNT0_0 0
#define TCNT0_1 1
#define TCNT0_2 2
#define TCNT0_3 3
#define TCNT0_4 4
#define TCNT0_5 5
#define TCNT0_6 6
#define TCNT0_7 7

#define TCCR0   _REG8_PROVIDE(0x33)
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7

#define MCUCSR  _REG8_PROVIDE(0x34)
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3
#define JTRF    4
#define ISC2    6
#define JTD     7

#define MCUCR   _REG8_PROVIDE(0x35)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define SM0     4
#define SM1     5
#define SE      6
#define SM2     7

#define TWCR    _REG8_PROVIDE(0x36)
#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7

#define SPMCSR  _REG8_PROVIDE(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define BLBSET  3
#define RWWSRE  4
#define RWWSB   6
#define SPMIE   7

#define TIFR    _REG8_PROVIDE(0x38)
#define TOV0    0
#define OCF0    1
#define TOV1    2
#define OCF1B   3
#define OCF1A   4
#define ICF1    5
#define TOV2    6
#define OCF2    7

#define TIMSK   _REG8_PROVIDE(0x39)
#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7

#define GIFR    _REG8_PROVIDE(0x3A)
#define INTF2   5
#define INTF0   6
#define INTF1   7

#define GICR    _REG8_PROVIDE(0x3B)
#define IVCE    0
#define IVSEL   1
#define INT2    5
#define INT0    6
#define INT1    7

#define OCR0    _REG8_PROVIDE(0x3C)
#define OCR0_0  0
#define OCR0_1  1
#define OCR0_2  2
#define OCR0_3  3
#define OCR0_4  4
#define OCR0_5  5
#define OCR0_6  6
#define OCR0_7  7

#define SPL     _REG8_PROVIDE(0x3D)
#define SP0     0
#define SP1     1
#define SP2     2
#define SP3     3
#define SP4     4
#define SP5     5
#define SP6     6
#define SP7     7

#define SPH     _REG8_PROVIDE(0x3D)
#define SP8     0
#define SP9     1
#define SP10    2

#define SREG    _REG8_PROVIDE(0x3F)
#define SREG_C  0
#define SREG_Z  1
#define SREG_N  2
#define SREG_V  3
#define SREG_S  4
#define SREG_H  5
#define SREG_T  6
#define SREG_I  7

/* ========================================================================= */
/* ================            INTERRUPT VECTORS            ================ */
/* ========================================================================= */

// Vector 0 is the reset vector

#define INT0_vect         __vector_1  /* External Interrupt Request 0 */
#define INT1_vect         __vector_2  /* External Interrupt Request 1 */
#define TIMER2_COMP_vect  __vector_3  /* Timer/Counter2 Compare Match */
#define TIMER2_OVF_vect   __vector_4  /* Timer/Counter2 Overflow */
#define TIMER1_CAPT_vect  __vector_5  /* Timer/Counter1 Capture Event */
#define TIMER1_COMPA_vect __vector_6  /* Timer/Counter1 Compare Match A */
#define TIMER1_COMPB_vect __vector_7  /* Timer/Counter1 Compare Match B */
#define TIMER1_OVF_vect   __vector_8  /* Timer/Counter1 Overflow */
#define TIMER0_OVF_vect   __vector_9  /* Timer/Counter0 Overflow */
#define SPI_STC_vect      __vector_10 /* Serial Transfer Complete */
#define USART_RXC_vect    __vector_11 /* USART, Rx Complete */
#define USART_UDRE_vect   __vector_12 /* USART Data Register Empty */
#define USART_TXC_vect    __vector_13 /* USART, Tx Complete */
#define ADC_vect          __vector_14 /* ADC Conversion Complete */
#define EE_RDY_vect       __vector_15 /* EEPROM Ready */
#define ANA_COMP_vect     __vector_16 /* Analog Comparator */
#define TWI_vect          __vector_17 /* 2-wire Serial Interface */
#define INT2_vect         __vector_18 /* External Interrupt Request 2 */
#define TIMER0_COMP_vect  __vector_19 /* Timer/Counter0 Compare Match */
#define SPM_RDY_vect      __vector_20 /* Store Program Memory Ready */

#endif /* MCU_REGISTERS_H */

/* ========================================================================= */
/* ================               END OF FILE               ================ */
/* ========================================================================= */
