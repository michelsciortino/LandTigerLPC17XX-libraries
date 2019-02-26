#include <LPC17xx.H>
#include "adc.h"
#include "../led/led.h"
#include "../speaker/speaker.h"
#include "../common.h"

unsigned short AD_current;   
unsigned short AD_last;									// Last converted value
uint8_t _adc_state;

void adc_init (void) {
	AD_last=0xFF;
	_adc_state = OFF;
  LPC_PINCON->PINSEL3 |=  (3UL<<30);    // P1.31 is AD0.5
  LPC_SC->PCONP       |=  (1<<12);      // Enable power to ADC block
  LPC_ADC->ADCR        =  (1<< 5) |     // select AD0.5 pin
                          (4<< 8) |     // ADC clock is 25MHz/5
                          (1<<21);      // enable ADC
  LPC_ADC->ADINTEN     =  (1<< 8);      // global enable interrupt
  NVIC_EnableIRQ(ADC_IRQn);             // enable ADC Interrupt
}

void adc_start_conversion (void) {
	if(_adc_state == ON)
		LPC_ADC->ADCR |=  (1<<24);            //Start A/D Conversion 
}				 

void ADC_IRQHandler(void) {
  AD_current = ((LPC_ADC->ADGDR>>4) & 0xFFF);	// Read Conversion Result
	
  if(AD_current != AD_last){ 		//If the adc input has changed
	// ad_last : AD_max = x : 7 	led_off((AD_last*7/0xFFF));	
	// ad_current : AD_max = x : 7 	led_on((AD_current*7/0xFFF));
	if(_adc_state == ON){
      		//insert here what to do when the adc changes value
    	}		
	AD_last = AD_current;
  }
}

void adc_enable(void){
	_adc_state = ON;
}

void adc_disable(void){
	_adc_state = OFF;
}
