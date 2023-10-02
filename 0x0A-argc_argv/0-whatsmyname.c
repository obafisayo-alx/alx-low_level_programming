#include "main.h"

/**
 * main - This is the main entry function
 * @argc: This is the argument count
 * @argv: This is the argument vector
 * Return: Always 0
*/
int main(int argc, char *argv[])
{
    int i;
    if (argc < 1)
    {
        perror("Name is not provided.");
    } else
    {
        for (i = 0; i < argc; i++)
        {
            printf("%s\n", argv[i]);
        }
    }
    return (0);
}