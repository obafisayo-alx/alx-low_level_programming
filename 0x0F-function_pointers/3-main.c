#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * main - return result of desired calculation from command line options
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: EXIT_SUCCESS on success, 98 for wrong number of arugments,
 * 99 for invalid operation, 99 for division/modulus by 0.
 */
int main(int argc, char *argv[])
{
	int retval, num1, num2;
	char *operator;
	int (*retptr)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	operator = argv[2];
	if ((operator[0] == '/' || operator[0] == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}
	retptr = get_op_func(operator);
	if (retptr == NULL)
	{
		puts("Error");
		exit(99);
	}
	retval = retptr(num1, num2);
	printf("%d\n", retval);
	exit(EXIT_SUCCESS);
}
