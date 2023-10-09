#include "main.h"

/**
* malloc_checked - This is used to create a malloc
* @b: This is the nmemb of memory to be created
* Return: This returns a pointer
*/
void* malloc_checked(unsigned int b)
{
	char *ptr;

	ptr = malloc(sizeof(char) * b);
	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}