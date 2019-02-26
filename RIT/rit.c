#include "lpc17xx.h"
#include "rit.h"
#include "../button/button.h"
#include "../ADC/adc.h"
#include "../joystick/joystick.h"
#include "../common.h"

void RIT_IRQHandler(void)
{
	//Buttons_Debouncing_Handler();			// Buttons debouncing
  	//Joystick_HANDLER();				// joystick management
	//adc_start_conversion();			// ADC management
	LPC_RIT->RICTRL |= 0x1;				// clear interrupt flag
	return;
}

void enable_RIT(void)
{
	LPC_RIT->RICTRL |= (1 << 3);
	return;
}

void disable_RIT(void)
{
	LPC_RIT->RICTRL &= ~(1 << 3);
	return;
}

void reset_RIT(void)
{
	LPC_RIT->RICOUNTER = 0; // Set count value to 0
	return;
}

uint32_t rit_init(uint32_t RITInterval)
{
	LPC_SC->PCLKSEL1 &= ~(3 << 26);
	LPC_SC->PCLKSEL1 |= (1 << 26);		// RIT Clock = CCLK
	LPC_SC->PCONP |= (1 << 16);				// Enable power for RIT
	LPC_RIT->RICOMPVAL = RITInterval; // Set match value
	LPC_RIT->RICTRL = (1 << 1) |			// Enable clear on match
										(1 << 2);				// Enable timer for debug
	LPC_RIT->RICOUNTER = 0;						// Set count value to 0
	NVIC_EnableIRQ(RIT_IRQn);
	return (0);
}
