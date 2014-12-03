/*
 * sensors.c
 *
 *  Created on: Dec 2, 2014
 *      Author: C16Austin.Bolinger
 */

#include "sensors.h"
#include <msp430g2553.h>

void left() {
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 = INCH_3;                       // input A4

	ADC10AE0 |= BIT3;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK

	P1DIR |= BIT0;

	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);      // LPM0, ADC10_ISR will force exit
	if (ADC10MEM < 0x1FF)
		P1OUT &= ~BIT0;                       // Clear P1.0 LED off

	else
		P1OUT |= BIT0;                        // Set P1.0 LED on
}

// Set P1.0 LED on

void middle() {
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 = INCH_4;                       // input A4

	ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK

//	P1DIR |= 0x01;                            // Set P1.0 to output direction
	P1DIR |= BIT0 | BIT6;

	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);      // LPM0, ADC10_ISR will force exit

	if (ADC10MEM < 0x1FF) {
		P1OUT &= ~(BIT0 | BIT6);
	}      // Clear P1.0 LED off

	else {
		P1OUT |= BIT0 | BIT6;                        // Set P1.0 LED on
	}
}

void right() {
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 = INCH_5;                       // input A4

	ADC10AE0 |= BIT5;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK

	P1DIR |= BIT6;

	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);      // LPM0, ADC10_ISR will force exit
	if (ADC10MEM < 0x1FF)
		P1OUT &= ~BIT6;                       // Clear P1.0 LED off

	else
		P1OUT |= BIT6;                        // Set P1.0 LED on
}
