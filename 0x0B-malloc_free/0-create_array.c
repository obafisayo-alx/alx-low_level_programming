#include "main.h"

/**
 * create_array - This function is used to create an array
 * @size: This is the size of the array
 * @c: This is the character to initialize it with
*/
char *create_array(unsigned int size, char c)
{
    if (size == 0)
    {
        return (NULL);
    }
    char *ar;
    
    ar = malloc(sizeof(char) * size);
    if (ar == NULL)
    {
        return (NULL);
    }
    ar[0] = c;
    return (ar);
}