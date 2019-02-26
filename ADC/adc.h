#ifndef __ADC_H_
#define __ADC_H_

void adc_init(void);
void adc_start_conversion(void);
void adc_IRQHandler(void);
void adc_enable(void);
void adc_disable(void);

#endif
