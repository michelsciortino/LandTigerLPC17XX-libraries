#ifndef __RIT_H_
#define __RIT_H_

uint32_t rit_init( uint32_t RITInterval );
void enable_RIT( void );
void disable_RIT( void );
void reset_RIT( void );
void RIT_IRQHandler (void);

#endif
