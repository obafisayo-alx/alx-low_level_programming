#include "lists.h"

/**
 * reverse_listint - Reverse linked list
 * @head: pointer to pointer to list head
 *
 * Return: Pointer to list head
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current_node;
	listint_t *prev_node = NULL;

	while (*head != NULL)
	{
		current_node = *head;
		*head = current_node->next;
		current_node->next = prev_node;
		prev_node = current_node;
	}
	*head = prev_node;
	return (*head);
}
