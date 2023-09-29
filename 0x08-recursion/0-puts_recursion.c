#include "main.h"

void print_char(char c)
{
    write(1, &c, 1);
}
void _puts_recursion(char *s)
{
    if (*s != '\0')
    {
        print_char(*s);
        _puts_recursion(s + 1);
    } else
        print_char('\n');
}