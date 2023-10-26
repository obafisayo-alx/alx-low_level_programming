#include "main.h"

/**
 * bin_to_uint - converts a bin number to an
 * unsigned int.
 * @b: bin.
 *
 * Return: unsigned int.
 */
unsigned int bin_to_uint(const char *b)
{
	unsigned int decimal;
	int i, bin;

	if (!b)
		return (0);

	decimal = 0;

	for (i = 0; b[i] != '\0'; i++)
		;

	for (i--, bin = 1; i >= 0; i--, bin *= 2)
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);
		}

		if (b[i] & 1)
		{
			decimal += bin;
		}
	}

	return (decimal);
}
