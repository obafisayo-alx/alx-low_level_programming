#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - free nodes previously allocated with malloc
 * @head: pointer to head of list
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
	
}
