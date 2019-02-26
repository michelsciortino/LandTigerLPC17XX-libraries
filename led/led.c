#include "lpc17xx.h"
#include "led.h"
#define LED_NUM     8   /* Number of user LEDs */

const unsigned long led_mask[] = { 1UL<<0, 1UL<<1, 1UL<<2, 1UL<< 3, 1UL<< 4, 1UL<< 5, 1UL<< 6, 1UL<< 7 };
unsigned char led_value;

void led_init(void) {
  LPC_PINCON->PINSEL4 &= 0xFFFF0000;	//PIN mode GPIO (00b value per P2.0 to P2.7)
	LPC_GPIO2->FIODIR   |= 0x000000FF;  //P2.0...P2.7 Output (LEDs on PORT2 defined as Output)
	LPC_GPIO2->FIOCLR    = 0x000000FF;  //all LEDs off
	led_value = 0;
}

void led_deinit(void) {
  LPC_GPIO2->FIODIR &= 0xFFFFFF00;  //P2.0...P2.7 Output LEDs on PORT2 defined as Output
}


/*----------------------------------------------------------------------------
  Function that turns on requested LED
 *----------------------------------------------------------------------------*/
void led_on(unsigned int num) {
 
  LPC_GPIO2->FIOPIN |= led_mask[num];
	led_value = LPC_GPIO2->FIOPIN;
}

/*----------------------------------------------------------------------------
  Function that turns off requested LED
 *----------------------------------------------------------------------------*/
void led_off(unsigned int num) {

  LPC_GPIO2->FIOPIN &= ~led_mask[num];
	led_value = LPC_GPIO2->FIOPIN;
}

/*----------------------------------------------------------------------------
  Function that outputs value to LEDs
 *----------------------------------------------------------------------------*/
void led_out(unsigned int mask) {
  int i;
  for (i = 0; i < LED_NUM; i++) {
    if (mask & (1<<i)) {
      led_on (i);
    } else {
      led_off(i);
    }
  }
	led_value = mask;
}
