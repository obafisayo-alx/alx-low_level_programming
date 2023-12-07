#include "function_pointers.h"

/**
 * int_index -  index of the first element for which the cmp function
 * @array: The array in context
 * @size: The size of the above array
 * @cmp: This is a function pointer
 * Return: This is index
*/
int int_index(int *array, int size, int (*cmp)(int))
{
	int i, index = -1;

	if (*cmp == NULL || array == NULL || size <= 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
		{
			index = i;
			return (index);
		}
	}
	return (-1);
}
