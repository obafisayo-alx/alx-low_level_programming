#include "main.h"

/**
 * _puts_recursion - This is the recursive function
 * @s: This is the string passed into this functon.
*/
void _puts_recursion(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	} else
		_putchar('\n');
}
