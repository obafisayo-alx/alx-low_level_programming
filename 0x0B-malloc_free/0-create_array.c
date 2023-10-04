#include "main.h"

/**
 * create_array - This function is used to create an array
 * @size: This is the size of the array
 * @c: This is the character to initialize it with
*/
char *create_array(unsigned int size, char c)
{
    char *ar;
    int i;

    if (size == 0)
    {
        return (NULL);
    }
    ar = malloc(sizeof(char) * size);
    if (ar == NULL)
    {
        return (NULL);
    }
    for (i = 0; i < size; i++)
    {
        ar[i] = c;
    }
    
    return (ar);
}