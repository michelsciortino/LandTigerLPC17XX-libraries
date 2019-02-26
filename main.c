#include <LPC17xx.H>
#include "led/led.h"
#include "button/button.h"
#include "RIT/rit.h"
#include "joystick/joystick.h"
#include "timer/timer.h"
#include "ADC/adc.h"
#include "speaker/speaker.h"

int main (void) {
  	
	SystemInit();  												/* System Initialization (i.e., PLL)  */
  led_init();                           /* LED Initialization                 */
  button_init();												/* BUTTON Initialization              */
	joystick_init();											/* Joystick initialization						*/
	rit_init(0x004C4B40);									/* RIT Initialization 50 msec       	*/
	enable_RIT();													/* RIT enabled												*/
	init_timer(TIMER1,0xB2D05E00,RESET,0); 	//25mhz * 120s
	start_timer(TIMER1);
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);						
		
  while (1) {                           /* Loop forever                       */	
		__ASM("wfi");
  }

}
