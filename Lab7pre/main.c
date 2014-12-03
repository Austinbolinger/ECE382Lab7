#include "sensors.h"
#include <msp430g2553.h>

void main(void) {
	WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

	while (1) {
		left();
		middle();
		right();
	}
}



// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
	__bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
