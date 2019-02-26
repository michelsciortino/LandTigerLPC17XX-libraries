#ifndef __BUTTON_H_
#define __BUTTON_H_
#include <LPC17xx.H>

void button_init(void);
uint8_t readInt0(void);
uint8_t readKey1(void);
uint8_t readKey2(void);
void EINT1_IRQHandler(void);
void EINT2_IRQHandler(void);
void EINT3_IRQHandler(void);
void Buttons_Debouncing_Handler(void);

#endif
