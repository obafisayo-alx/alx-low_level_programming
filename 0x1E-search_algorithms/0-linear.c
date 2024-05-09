#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers
 * using the linear search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: is the value to search for
 * 
 * Return: value on success and -1 when value is not present in the array
 * or the array is NULL
*/
int linear_search(int *array, size_t size, int value)
{
     size_t i = 0;

     if (array == NULL)
          return (-1);
     for (i = 0; i < size; i++)
     {
          printf("Value checked array[%ld] = [%d] \n", i, array[i]);
          if (array[i] == value)
               return (i);
     }
     return (-1);
}
