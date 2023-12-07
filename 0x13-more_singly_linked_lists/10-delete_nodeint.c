#include "lists.h"

/**
 * delete_nodeint_at_index - delete node at index `index' from list `head'
 * @head: pointer to pointer to beginning of list
 * @index: index at which to delete node, if possible
 *
 * Return: 1 if succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *temp_node, *current = *head;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}
	for (i = 0; i < index - 1; i++)
	{
		if (current == NULL)
			return (-1);
		if (current->next == NULL)
			return (-1);
		current = current->next;
	}
	temp_node = current->next;
	if (temp_node == NULL)
		return (-1);
	current->next = temp_node->next;
	free(temp_node);
	return (1);
}
