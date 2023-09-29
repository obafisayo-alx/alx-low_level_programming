#include "main.h"
/**
 * print_char - This is the function that is used to print each character.
 * @c: This is the characer to be printed.
 */
void print_char(char c)
{
    write(1, &c, 1);
}

/**
 * _puts_recursion - This is the recursive function
 * @s: This is the string passed into this functon.
 * 
*/
void _puts_recursion(char *s)
{
    if (*s != '\0')
    {
        print_char(*s);
        _puts_recursion(s + 1);
    } else
        print_char('\n');
}