/* source: https://forum.osdev.org/viewtopic.php?t=10247 */

/* kbdhandler.c - kbdhandler */

#include <xinu.h>

unsigned char get_scancode()
{
    unsigned char inputdata;
    inputdata = inportb(KEYBOARD_DATAREG);
    return inputdata;
}


/*------------------------------------------------------------------------
 *  kbdhandler  -  Handle an interrupt for the keyboard device
 *------------------------------------------------------------------------
 */
void kbdhandler(void)
{
	int n;

	kbdc.key = get_scancode();
	n = semcount(kbdc.kbdsem);
	if (n < 1)
		signal(kbdc.kbdsem);
	
}

