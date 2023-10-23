#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - add new node at beginning of list pointed to by `head'
 * @head: pointer to pointer to beginning of list
 * @n: value with which to initialize new element
 *
 * Return: pointer to new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *temp_node;

	temp_node = malloc(sizeof(listint_t));
	if (temp_node == NULL)
		return (NULL);
	temp_node->n = n;
	temp_node->next = *head;
	*head = temp_node;
	return (temp_node);
}