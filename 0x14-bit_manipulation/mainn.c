#include "main.h"
// #include <stdio.h>
// #include <string.h>

// unsigned int binary_to_uint(const char *b)
// {
//    if (!b) {
//        return (0);
//    }

//    unsigned int decimal_value = 0;
//    int length = strlen(b);

//    for (int i = 0; i < length; i++) {
//        char current_char = b[i];

//        if (current_char == '0') {
//            decimal_value *=  2;
//        } else if (current_char == '1') {
//            decimal_value = decimal_value * 2 + 1;
//        } else {
//            return 0; // Return 0 if a non-binary character is encountered
//        }
//    }

//    return decimal_value;
// }

// unsigned int binary_to_uint(const char *b)
// {
// 	unsigned int ui;
// 	int len, base_two;

// 	if (!b)
// 		return (0);

// 	ui = 0;

// 	for (len = 0; b[len] != '\0'; len++)
// 		;

// 	for (len--, base_two = 1; len >= 0; len--, base_two *= 2)
// 	{
// 		if (b[len] != '0' && b[len] != '1')
// 		{
// 			return (0);
// 		}

// 		if (b[len] & 1)
// 		{
// 			ui += base_two;
// 		}
// 	}

// 	return (ui);
// }

/**
 * main - check the code
 *
 * Return: Always 0.
 */

// #include <stdio.h>

int main(void)
{
    unsigned int n;

    n = binary_to_uint("1");
    printf("%u\n", n);
    n = binary_to_uint("101");
    printf("%u\n", n);
    n = binary_to_uint("1e01");
    printf("%u\n", n);
    n = binary_to_uint("1100010");
    printf("%u\n", n);
    n = binary_to_uint("0000000000000000000110010010");
    printf("%u\n", n);
    return (0);
}