#include <stdio.h>
#include "list.h"

/**
 * print_listint - a function that prints all the elements of a listint_t list.
 * @h: struct
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	int no_of_nodes = 0;

	if (h == NULL)
		return (0);
	while (h != NULL)
	{
		if (h->n != NULL)
		{
			printf("%d\n", h->n);
		}
		h = h->next;
		no_of_nodes++;
	}	
	return (no_of_nodes);
}

