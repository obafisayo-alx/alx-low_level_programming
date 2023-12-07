#include "lists.h"

/**
 * sum_dlistint - sums all the data of a linked list
 * @head: pointer to the head of the list
 * Return: the sum of all the data of the linked list
*/
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	int i = 0;

	current = head;
	if (head == NULL)
		return (0);
	while (current != NULL)
	{
		i += current->n;
		current = current->next;
	}
	return (i);
}
