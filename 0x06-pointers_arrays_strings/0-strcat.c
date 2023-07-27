#include "main.h"
#include <string.h>
/**
 * _strcat - concats two arrays
 *
 * @dest: destination of concat
 * @src: source array to concat
 *
 * Return: char value
 */
char *_strcat(char *dest, char *src)
{
	strcat(dest, src);
	return (dest);
}
