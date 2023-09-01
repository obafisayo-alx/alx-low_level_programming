#include <string.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to an
 * unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
    if (!b) {
        return (0);
    }

    unsigned int decimal_value = 0;
    int length = strlen(b);

    for (int i = 0; i < length; i++) {
        char current_char = b[i];

        if (current_char == '0') {
            decimal_value = decimal_value * 2;
        } else if (current_char == '1') {
            decimal_value = decimal_value * 2 + 1;
        } else {
            return (0); // Return 0 if a non-binary character is encountered
        }
    }

    return (decimal_value);
}
