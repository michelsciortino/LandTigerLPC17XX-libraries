#ifndef __TIMER_H_
#define __TIMER_H_

enum timer
{
    TIMER0 = 0,
    TIMER1 = 1,
    TIMER2 = 2,
    TIMER3 = 3
};

enum MCR_values
{
		INTERRUPT = 1,
    RESET = 2,
    STOP = 4
};

void init_timer(uint8_t timer_num, uint32_t timer_interval, uint32_t mode, uint8_t priority);
void start_timer(uint8_t timer_num);
void pause_timer(uint8_t timer_num);
void reset_timer(uint8_t timer_num);
void pow_timer(uint8_t timer_num, uint8_t state);
void TIMER0_IRQHandler(void);
void TIMER1_IRQHandler(void);
void TIMER2_IRQHandler(void);
void TIMER3_IRQHandler(void);

#endif
