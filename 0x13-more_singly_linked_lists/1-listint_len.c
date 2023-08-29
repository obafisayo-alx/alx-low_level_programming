#include "lists.h"

/**
 * listint_len - compute number of elements in list `h'
 * @h: pointer to head of list
 *
 * Return: total number of nodes
 */
size_t listint_len(const listint_t *h)
{
	if (h == NULL)
		return (0);

	size_t i;

	for (i = 0; h->n != NULL; ++i)
	{
		h = h->next;
	}
	return (i);
}
