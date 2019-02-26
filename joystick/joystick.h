#ifndef __JOYSTICK_H_
#define __JOYSTICK_H_

void joystick_init(void);
void Joystick_HANDLER(void);	/* Main handler for joystick input	*/
void JCenter_HANDLER (void);	/* Joystick CENTER button pressed	*/
void JDown_HANDLER (void);	  	/* Joystick DOWN button pressed     */
void JLeft_HANDLER (void);	  	/* Joystick LEFT button pressed 	*/
void JRight_HANDLER (void);	  	/* Joystick RIGHT button pressed	*/
void JUp_HANDLER (void);	  	/* Joystick UP button pressed		*/

#endif
