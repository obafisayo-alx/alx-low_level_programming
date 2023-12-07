#include "lists.h"

/**
 * print_listint - This prints all the element of the strucure;
 * @h: This is a pointer to a structure
 * Return: this is the number of elemets found
*/
size_t print_listint(const listint_t *h)
{
	size_t j;

	for (j = 0; h != NULL; ++j)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (j);
}
