#include "main.h"

int _sqrt_helper(int n, int guess);
/**
 * _sqrt_recursion - This returns the square root of number.
 * @n: This is the number to be handled.
 * Return: This returns an integer value.
*/
int _sqrt_recursion(int n)
{
    if (n < 0)
    {
        return (-1);
    }
    if ( n == 0 || n == 1)
    {
        return n;
    }
    return (_sqrt_helper(n, n / 2));
}

/**
 * _sqrt_helper - This helps to determine the value of the sqrt
 * @n: This is still the number to be handled.
 * @guess: This is the determinant.
 * Return: This is still the same return value.
*/
int _sqrt_helper(int n, int guess)
{
    if (guess * guess == n)
    {
        return (guess);
    } else if (guess * guess < n)
    {
        return _sqrt_helper(n, guess + 1);
    } else
    {
        return (_sqrt_helper(n, guess - 1));
    }
}