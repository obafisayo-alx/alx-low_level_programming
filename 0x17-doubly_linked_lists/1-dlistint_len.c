#include "lists.h"

/**
 * dlistint_len - this calculates the length of the list
 * @h: the pointer to the head of the node
 * Return: the number of the nodes found
*/
size_t dlistint_len(const dlistint_t *h)
{
	size_t i;

	for (i = 0; h != NULL; i++)
	{
		h = h->next;
	}
	return (i);
}
