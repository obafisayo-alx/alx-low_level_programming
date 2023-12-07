#include "lists.h"

/**
 * listint_len - compute number of elements in list `h'
 * @h: pointer to head of list
 *
 * Return: total number of nodes
 */
size_t listint_len(const listint_t *h)
{
	int num;

	for (num = 0; h != NULL; ++num)
	{
		h = h->next;
	}
	return (num);
}
