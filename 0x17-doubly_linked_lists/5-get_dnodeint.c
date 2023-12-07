#include "lists.h"

/**
 * get_dnodeint_at_index - gets the nth node of a linked list
 * @head: pointer to the head of the node
 * @index: the index of the node being searched
 * Return: the node of the particular index or NULL if not found
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;
	size_t i;

	if (head == NULL)
		return (NULL);
	current = head;
	for (i = 0; i < index; i++)
	{
		current = current->next;
		if (current->next == NULL)
			return (NULL);
	}
	return (current);
}
