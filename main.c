//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

	// Setting the direction register for Port 1 line 1
	P1DIR|=BIT0;

	// Setting the function of the line by setting the select registers
	// for port 1 line 1.
	
	if(P1SEL0 & BIT0){
		if(P1SEL1 & BIT0){
			P1SELC|=BIT0; // Changing both at the same time
		} else {
			P1SEL0&=~BIT0; // Changing only the one in register 0
		}
	} else if (P1SEL1 & BIT0){
		P1SEL1&=~BIT0; // Changing only the one in register 1
	}
	
	// Turn the LED on
	P1OUT|=BIT0;

	// MAIN LOOP
	while(1){
		// Delay
		volatile int i;
		for(i=0;i<20000;++i);

		// Toggle the output on pin 0 of port 1.
		P1OUT^=BIT0;
	}
}
