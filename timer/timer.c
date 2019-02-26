#include "lpc17xx.h"
#include "timer.h"
#include "../common.h"
#include "../led/led.h"
#include "../button/button.h"

static uint8_t _t0state=ON;
static uint8_t _t1state=ON;
static uint8_t _t2state=OFF;
static uint8_t _t3state=OFF;

extern uint8_t e1;
extern uint8_t e2;


void TIMER0_IRQHandler(void) //	USED TO CHANGE STATE
{
	//code here
	LPC_TIM0->IR = 1; /* clear interrupt flag */
	return;
}

void TIMER1_IRQHandler(void) // USED FOR LIGHT BLINKING
{
	//code here
	LPC_TIM1->IR = 1; /* clear interrupt flag */
	return;
}

void TIMER2_IRQHandler(void) // USED TO PLAY SPEAKER SOUND
{
	//code here
	LPC_TIM2->IR = 1; /* clear interrupt flag */
	return;
}

void TIMER3_IRQHandler(void) // USED FOR SPEAKER RINGING
{
	//code here
	LPC_TIM3->IR = 1; /* clear interrupt flag */
	return;
}

void start_timer(uint8_t timer_num)
{
	switch (timer_num)
	{
	case TIMER0:
		pow_timer(TIMER0, ON);
		LPC_TIM0->TCR = 1;
		break;
	case TIMER1:
		pow_timer(TIMER1, ON);
		LPC_TIM1->TCR = 1;
		break;
	case TIMER2:
		pow_timer(TIMER2, ON);
		LPC_TIM2->TCR = 1;
		break;
	case TIMER3:
		pow_timer(TIMER3, ON);
		LPC_TIM3->TCR = 1;
		break;
	default:
		break;
	}
	return;
}

void pause_timer(uint8_t timer_num)
{
	switch (timer_num)
	{
	case TIMER0:
		LPC_TIM0->TCR = 0;
		break;
	case TIMER1:
		LPC_TIM1->TCR = 0;
		break;
	case TIMER2:
		LPC_TIM2->TCR = 0;
		break;
	case TIMER3:
		LPC_TIM3->TCR = 0;
		break;
	}
	return;
}

void reset_timer(uint8_t timer_num)
{
	switch (timer_num)
	{
	case TIMER0:
		LPC_TIM0->TCR |= 0x02;
		break;
	case TIMER1:
		LPC_TIM1->TCR |= 0x02;
		break;
	case TIMER2:
		LPC_TIM2->TCR |= 0x02;
		break;
	case TIMER3:
		LPC_TIM3->TCR |= 0x02;
		break;
	default:
		break;
	}
	return;
}

void init_timer(uint8_t timer_num, uint32_t timer_interval, uint32_t mode, uint8_t priority)
{
	switch (timer_num)
	{
	case TIMER0:
		pow_timer(TIMER0, ON);
		LPC_TIM0->MR0 = timer_interval;
		LPC_TIM0->MCR = mode;
		LPC_TIM0->TC = 0;
		NVIC_EnableIRQ(TIMER0_IRQn);
		NVIC_SetPriority(TIMER0_IRQn, priority);
		break;
	case TIMER1:
		pow_timer(TIMER1, ON);
		LPC_TIM1->MR0 = timer_interval;
		LPC_TIM1->MCR = mode;
		LPC_TIM1->TC = 0;
		NVIC_EnableIRQ(TIMER1_IRQn);
		NVIC_SetPriority(TIMER1_IRQn, priority);
		break;
	case TIMER2:
		pow_timer(TIMER2, ON);
		LPC_TIM2->MR0 = timer_interval;
		LPC_TIM2->MCR = mode;
		LPC_TIM2->TC = 0;
		NVIC_EnableIRQ(TIMER2_IRQn);
		NVIC_SetPriority(TIMER2_IRQn, priority);
		break;
	case TIMER3:
		pow_timer(TIMER3, ON);
		LPC_TIM3->MR0 = timer_interval;
		LPC_TIM3->MCR = mode;
		LPC_TIM3->TC = 0;
		NVIC_EnableIRQ(TIMER3_IRQn);
		NVIC_SetPriority(TIMER3_IRQn, priority);
		break;
	default:
		break;
	}
	return;
}

void pow_timer(uint8_t timer_num, uint8_t state)
{
	switch (timer_num)
	{
	case TIMER0:
		if (state == ON && _t0state==OFF){
			LPC_SC->PCONP |= (1 << 1);
			_t0state=ON;
		}
		if (state == OFF && _t0state==ON){
			LPC_SC->PCONP &= (0xFFFFFFFD);
			_t0state=OFF;
		}
		break;
	case TIMER1:
		if (state == ON && _t1state==OFF){
			LPC_SC->PCONP |= (1 << 2);
			_t1state=ON;
		}
		if (state == OFF && _t1state==ON){
			LPC_SC->PCONP &= (0xFFFFFFFB);
			_t1state=OFF;
		}
		break;
	case TIMER2:
		if (state == ON && _t2state==OFF){
			LPC_SC->PCONP |= (1 << 22);
			_t2state=ON;
		}
		if (state == OFF && _t2state==ON){
			LPC_SC->PCONP &= (0xFFBFFFFF);			
			_t2state=OFF;
		}
		break;
	case TIMER3:
		if (state == ON && _t3state==OFF){
			LPC_SC->PCONP |= (1 << 23);
			_t3state=ON;
		}
		if (state == OFF && _t3state==ON){
			LPC_SC->PCONP &= (0xFF7FFFFF);
			_t3state=OFF;
		}
		break;
	default:
		break;
	}
}
