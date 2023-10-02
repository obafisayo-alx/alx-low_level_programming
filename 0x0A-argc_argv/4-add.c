#include "main.h"

/**
 * main - This is the main entry function
 * @argc: This is the argument count
 * @argv: This is the argument vector
 * Return: Always 0
*/
int main(int argc, char *argv[])
{
    int i, j, mul = 0;
    if (argc < 1)
    {
        printf("Error\n");
        return (1);
    } else
    {
        for (i = 1; i < argc; i++)
        {
            for (j = 0; argv[i][j] != '\0' ; j++)
            {
                if (argv[i][j] < 47 || argv[i][j] > 57)
                {
                    printf("Error\n");
                    return (1);
                }
            }
               mul += atoi(argv[i]);
        }
        printf("%d\n", mul);
    }
    return (0);
}