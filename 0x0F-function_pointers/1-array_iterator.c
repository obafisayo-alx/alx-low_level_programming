#include "function_pointers.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * array_iterator - This is an array iterator
 * @array: This is the array
 * @size: This is the size
 * @action: This is a function pointer
 * Return: This is void
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
    int i;

    for (i = 0; i < size; i++)
    {
        action(array[i]);
    }
    return ;
}
