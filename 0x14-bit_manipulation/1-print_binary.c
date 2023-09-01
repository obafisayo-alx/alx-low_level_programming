#include <stdio.h>
#include <main.h>

/**
 * _print_binary - recursively print rightmost bit of non-zero number
 * in its binary representation.
 * @n: number to print
 */
void print_binary(unsigned long int n)
{
    if (n == 0)
    {
        printf("0");
    }

    int start_printing_zeros = 0;
    int i, bit_count = sizeof(n) * 8;
    unsigned long int mask = 1UL << (bit_count - 1);

    for ( i = 0 ; i < bit_count ; i++ )
    {
        if ((mask & n) != 0)
        {
            start_printing_zeros = 1;
            printf("1");
        } else if (start_printing_zeros)
        {
            printf("0");
        }
        mask >>= 1;
    }
}

