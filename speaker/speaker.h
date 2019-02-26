#ifndef __SPEAKER_H_
#define __SPEAKER_H_

void speaker_init(void);
void speaker_set_volume(float volume);
void speaker_pulse(void);
void speaker_set_freq(int freq);

void speaker_update(void);
void speaker_turn_on(void);
void speaker_turn_off(void);

#endif
