#ifndef __LED_H_
#define __LED_H_

void led_init(void);
void led_deinit(void);
void led_on (unsigned int num);
void led_off (unsigned int num);
void led_out(unsigned int value);

#endif
