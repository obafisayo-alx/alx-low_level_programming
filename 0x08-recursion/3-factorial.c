#include "main.h"

/**
 * factorial - This is a function that returns the factorial of a number.
 * @n: This is the integer.
 * Return: This the factorial of a number.
*/
int factorial(int n)
{
    if (n < 0)
    {
        return (-1);
    } else if (n == 0)
    {
        return (1);
    } else
    {
        return (n * factorial(n - 1));
    }
}