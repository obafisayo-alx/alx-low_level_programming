#include "lists.h"

void free_listint2(listint_t **head)
{
    listint_t *current, *tmp;

    if (head == NULL || *head == NULL)
	   return;

    current = *head;

    while (current != NULL)
    {
	   tmp = current->next;
	   free(current);
	   current = tmp;
    }

    *head = NULL;
}
