#include "main.h"

/**
 * binary_to_decimalnt - converts a binary number to an
 * unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */
unsigned int binary_to_decimalnt(const char *b)
{
	unsigned int decimal;
	int length, base_two;

	if (!b)
		return (0);

	decimal = 0;

	for (length = 0; b[length] != '\0'; length++)
		;

	for (length--, base_two = 1; length >= 0; length--, base_two *= 2)
	{
		if (b[length] != '0' && b[length] != '1')
		{
			return (0);
		}

		if (b[length] & 1)
		{
			decimal += base_two;
		}
	}

	return (decimal);
}
