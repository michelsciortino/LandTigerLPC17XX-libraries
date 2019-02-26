#include "lpc17xx.h"
#include "joystick.h"
#include "../led/led.h"
#include "../timer/timer.h"
#define N 10

uint8_t center, down, left, right, up;

extern int overflow(int v[N], int n);

static int _pressed_count=0;
static int values[N];

void JCenter_HANDLER(void)
{   /* Joystick CENTER button pressed	*/
	//code here
}

void JDown_HANDLER(void)
{   /* Joystick DOWN button pressed	*/
	//code here
}

void JLeft_HANDLER(void)
{   /* Joystick LEFT button pressed	*/
	//code here
}

void JRight_HANDLER(void)
{   /* Joystick RIGHT button pressed */
	//code here
}

void JUp_HANDLER(void)
{   /* Joystick UP button pressed */
		//code here
}

void Joystick_HANDLER(void)
{ /* Main handler for joystick input	*/
	static int center = 0, down = 0, left = 0, right = 0, up = 0;
	uint32_t value;

	if ((LPC_GPIO1->FIOPIN & (1 << 25)) == 0)
	{ /* Joytick SELECT pressed */
		center++;
		if (center == 2)
			JCenter_HANDLER();
	}
	else
	{
		center = 0;
	}

	if ((LPC_GPIO1->FIOPIN & (1 << 26)) == 0)
	{ /* Joytick DOWN pressed */
		down++;
		if (down == 2)
			JDown_HANDLER();
	}
	else
	{
		down = 0;
	}

	if ((LPC_GPIO1->FIOPIN & (1 << 27)) == 0)
	{ /* Joytick LEFT pressed */
		left++;
		if (left == 2)
			JLeft_HANDLER();
	}
	else
	{
		left = 0;
	}

	if ((LPC_GPIO1->FIOPIN & (1 << 28)) == 0)
	{ /* Joytick RIGHT pressed */
		right++;
		if (right == 2)
			JRight_HANDLER();
	}
	else
	{
		right = 0;
	}

	if ((LPC_GPIO1->FIOPIN & (1 << 29)) == 0)
	{ /* Joytick UP pressed */
		up++;
		if (up == 2){
			JUp_HANDLER();
		}
	}
	else if(up > 0)
	{
		//code here
		up = 0;
	}
}

void joystick_init(void)
{
	//enabling center key
	LPC_PINCON->PINSEL3 &= ~(3 << 18); //PIN mode GPIO (00b value per P1.25)
	LPC_GPIO1->FIODIR &= ~(1 << 25);   //P1.25 Input (joysticks on PORT1 defined as Input)

	//enabling down key
	LPC_PINCON->PINSEL3 &= ~(3 << 20); //PIN mode GPIO (00b value per P1.25)
	LPC_GPIO1->FIODIR &= ~(1 << 26);   //P1.25 Input (joysticks on PORT1 defined as Input)

	//enabling left key
	LPC_PINCON->PINSEL3 &= ~(3 << 22); //PIN mode GPIO (00b value per P1.25)
	LPC_GPIO1->FIODIR &= ~(1 << 27);   //P1.25 Input (joysticks on PORT1 defined as Input)

	//enabling right
	LPC_PINCON->PINSEL3 &= ~(3 << 24); //PIN mode GPIO (00b value per P1.25)
	LPC_GPIO1->FIODIR &= ~(1 << 28);   //P1.25 Input (joysticks on PORT1 defined as Input)

	//enabling up key
	LPC_PINCON->PINSEL3 &= ~(3 << 26); //PIN mode GPIO (00b value per P1.25)
	LPC_GPIO1->FIODIR &= ~(1 << 29);   //P1.25 Input (joysticks on PORT1 defined as Input)
}
