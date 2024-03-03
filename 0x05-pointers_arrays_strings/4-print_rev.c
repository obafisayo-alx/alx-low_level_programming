#include "main.h"

/**
 * print_rev - prints a string in reverse followed by a new line
 * @s: the string to be printed in reverse
*/
void print_rev(char *s)
{
	char first;

	first = *s;
	while (*s != '\0')
	{
		s++;
	}
	while (*s != first)
	{
		_putchar(*s);
	}
	_putchar('\n');
}
