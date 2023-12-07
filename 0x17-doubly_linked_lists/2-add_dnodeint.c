#include "lists.h"

/**
 * add_dnodeint - adds a node to the start of the doubly linked list
 * @head: pointer to the head of the list
 * Return: the new node that was added
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *current;

	current = *head;
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		while (current->prev != NULL)
			current = current->prev;
		current->prev = new_node;
		new_node->next = current;
		*head = new_node;
	}

	return (new_node);
}
