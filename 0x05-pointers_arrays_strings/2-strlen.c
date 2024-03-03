#include "main.h"
#include <stdio.h>

/**
 * _strlen - function that returns the length of a string
 * @s: string to get the length
 *
 * Return: the length of the string
*/
int _strlen(char *s)
{
	int count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return count;
}
