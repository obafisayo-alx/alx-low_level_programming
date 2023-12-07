#include "lists.h"

/**
 * insert_nodeint_at_index - insert new node into list `head' at index `index'
 * @head: pointer to pointer to head of list
 * @idx: index where new node should be added
 * @n: value with which to initialize new node
 *
 * Return: pointer to new node, or NULL if fails. If `idx' - 1 is out of
 * range, return NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *temp_node, *new_node, *current = *head;
	unsigned int i;

	if (idx == 0)
	{
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL)
			return (NULL);
		new_node->next	= *head;
		new_node->n = n;
		*head = new_node;
		return (new_node);
	}
	for (i = 0; i < idx - 1; i++)
	{
		if (current == NULL)
			return (NULL);
		current = (current)->next;
	}
	if (current == NULL)
		return (NULL);
	temp_node = current->next;
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	current->next = new_node;
	new_node->next = temp_node;
	return (new_node);
}
