#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * first - print message beforew it even lets main to execute
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n"
	       "I bore my house upon my back!\n");
}
