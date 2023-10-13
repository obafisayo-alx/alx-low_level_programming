#include "function_pointers.h"

/**
 * print_name - This function prints the name
 * @name: This is the name to be printed
 * @f: This is the function pointer
 * Return: This returns void
*/
void print_name(char *name, void (*f)(char *))
{
	if (*f == NULL)
		return;
	f(name);
}
