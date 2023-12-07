#include "main.h"

/**
 * _print_rev_recursion - This is the function for this file.
 * @s: This is the string to be passed.
*/
void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
