#include "main.h"

/**
 * main - This is the main entry function
 * @argc: This is the argument count
 * @av: This is the argument vector
 * Return: Always 0
*/
int main(int argc, char *av[])
{
	if (av[0])
	{
		printf("%d\n", argc - 1);
	}
	return (0);
}
