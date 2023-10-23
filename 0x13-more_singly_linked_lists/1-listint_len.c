#include "lists.h"

size_t listint_len(const listint_t *h)
{
	int num;
	
	for (num = 0; h != NULL; ++num)
	{
		h = h->next;
	}
	return (num);
}