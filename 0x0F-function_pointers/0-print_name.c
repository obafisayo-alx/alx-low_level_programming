#include "function_pointers.h"

/**
 * print_name - This function prints the name
 * @name: This is the name to be printed
*/
void print_name(char *name, void (*f)(char *))
{
        f(name);
}