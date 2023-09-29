#include "main.h"

/**
 * _pow_recursion - This is the recursion function.
 * @x: This is the value.
 * @y: This is the power.
*/
int _pow_recursion(int x, int y)
{
    if (y < 0)
        return (-1);
    if (y == 0)
    {
        return (1);
    } else
    {
        return (x * _pow_recursion(x, (y - 1)));
    }
}