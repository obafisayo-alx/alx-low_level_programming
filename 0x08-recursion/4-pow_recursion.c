#include "main.h"

/**
 * _pow_recursion - This is the recursion function.
 * @x: This is the value.
 * @y: This is the power.
 * Return: This is the return value of the function.
*/
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
	{
		return (1);
	}
	return (x * _pow_recursion(x, (y - 1)));
}
