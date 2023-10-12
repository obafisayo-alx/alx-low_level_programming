#include "function_pointers.h"

/**
 * print_name - This function prints the name
 * @name: This is the name to be printed
 * Return: This returns void
*/
void print_name(char *name, void (*f)(char *))
{
        f(name);
        return;
}