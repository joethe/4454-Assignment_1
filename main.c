//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

    //////////////////////////////
    // Configuring Output Pins
    //////////////////////////////

	// Setting the direction register for Port 1 line 0
	P1DIR|=BIT0;

	// Setting the function of the line by setting the select registers
	// for port 1 line 0.
	
	if(P1SEL0 & BIT0){
		if(P1SEL1 & BIT0){
			P1SELC|=BIT0; // Changing both at the same time
		} else {
			P1SEL0&=~BIT0; // Changing only the one in register 0
		}
	} else if (P1SEL1 & BIT0){
		P1SEL1&=~BIT0; // Changing only the one in register 1
	}
	
	////////////////////////////
	// Configuring Input Pins
	////////////////////////////

	// Setting the direction of port 1 line 1
	P1DIR&=~BIT1;

	// Setting pullup resistor
	P1REN|=BIT1;
	P1OUT|=BIT1;

	// Setting the function of the line by setting the select registers
	// Port 1 Line 1
	if(P1SEL0 & BIT1){
		if(P1SEL1 & BIT1){
			P1SELC|=BIT1; // Changing both at the same time
		} else {
			P1SEL0&=~BIT1; // Changing only the one in register 0
		}
	} else if (P1SEL1 & BIT1){
		P1SEL1&=~BIT1; // Changing only the one in register 1
	}

	////////////////////////////
	// Running the things
	////////////////////////////

	// Turn the LED on
	P1OUT|=BIT0;

	// MAIN LOOP
	while(1){

		// Toggle the output on pin 0 of port 1.
		unsigned char portIn=P1IN;
		if(!(portIn & BIT1)){
			P1OUT^=BIT0;
		}

		// Delay
		volatile int i;
		for(i=0;i<20000;++i);
	}
}
