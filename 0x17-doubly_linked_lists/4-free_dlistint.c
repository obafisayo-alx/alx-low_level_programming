#include "lists.h"

/**
 * free_dlistint - frees a list
 * @head: pointer to head af the list
*/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}

}
