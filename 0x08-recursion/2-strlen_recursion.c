#include "main.h"

/**
 * _strlen_recursion - This is the recursive function.
 * @s: This is the string to be passed.
 * Return: The return value is the length of the string.
*/
int _strlen_recursion(char *s)
{
	int len = 0;

	if (*s != '\0')
	{
		len++;
		len += _strlen_recursion(s + 1);
	}
	return (len);
}
