#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node at a particular index
 * @h: pointer to the head of the node
 * @idx: index to add new node
 * @n: new integer to be added
 * Return: 
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current, *new_node;
	size_t i;

	if (*h == NULL)
		return (NULL);
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	if (idx == 0)
	{
		new_node->next = *h;
		new_node->prev = NULL;
		if (*h != NULL)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}
	current = *h;
	for (i = 0; i < idx && current != NULL; i++)
		current = current->next;
	if (i < idx)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = current;
	new_node->prev = current->prev;
	if (current->prev != NULL)
		current->prev->next = new_node;
	current->prev = new_node;
	return (new_node);
}
