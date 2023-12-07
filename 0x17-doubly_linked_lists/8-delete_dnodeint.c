#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at a particular index
 * @head: the pointer to the head of the function
 * @index: the index to be deleted
 * Return: 1 if succeeded and -1 if failed
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *deleted_node;
	size_t i;

	if (*head == NULL)
		return (-1);
	current = *head;
	if (index == 0)
	{
		if (current->next != NULL)
			current->next->prev = NULL;
		*head = current->next;
		free(current);
		return (1);
	}
	for (i = 0; i < index && current != NULL; i++)
		current = current->next;
	if (i < index || current == NULL)
		return (-1);
	deleted_node = current;
	if (current->next != NULL)
		current->next->prev = current->prev;
	if (current->prev != NULL)
		current->prev->next = current->next;
	free(deleted_node);
	return (1);
}
