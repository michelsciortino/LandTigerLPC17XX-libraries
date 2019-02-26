#include <LPC17xx.H>
#include "speaker.h"
#include "../timer/timer.h"
#include "../common.h"

static int _sin_iterator;
static float _volume;
static uint8_t _speaker_state;

const int freqs[8]={2120,1890,1684,1592,1417,1263,1125,1062};
/*
262Hz	k=2120		c4
294Hz	k=1890		
330Hz	k=1684		
349Hz	k=1592		
392Hz	k=1417		
440Hz	k=1263		
494Hz	k=1125		
523Hz	k=1062		c5
*/

const uint16_t SinTable[45] =
{
    410, 467, 523, 576, 627, 673, 714, 749, 778,
    799, 813, 819, 817, 807, 789, 764, 732, 694, 
    650, 602, 550, 495, 438, 381, 324, 270, 217,
    169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
    20 , 41 , 70 , 105, 146, 193, 243, 297, 353
};

void speaker_init(void){
	_sin_iterator=0;
	_volume=1;
	_speaker_state= OFF;
	LPC_PINCON->PINSEL1 |= (1<<21);
	LPC_PINCON->PINSEL1 &= ~(1<<20);
	LPC_GPIO0->FIODIR |= (1<<26);
	return;
}

void speaker_pulse(void){
	if(_speaker_state == OFF)
		return;
	LPC_DAC->DACR = ((int)(((float)SinTable[_sin_iterator])*_volume))<<6;
	_sin_iterator++;
	if(_sin_iterator==45)
		_sin_iterator=0;
	return;
}

void speaker_set_volume(float volume){
	_volume=(1-volume) * 1.2;
	return;
}

void speaker_turn_on(void){
	_speaker_state = ON;
	
	pause_timer(2);
	reset_timer(2);
	init_timer(2,freqs[7],INTERRUPT|RESET,0);
	start_timer(2);
	
	return;
}

void speaker_turn_off(void){
	_speaker_state = OFF;
	pause_timer(2);
	return;
}
