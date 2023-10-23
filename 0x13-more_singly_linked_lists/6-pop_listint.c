#include "lists.h"

/**
 * pop_listint - delete head node of list pointed to by `head'
 * @head: pointer to pointer to head node of list
 *
 * Return: integer stored by deleted node
 */
int pop_listint(listint_t **head)
{
     listint_t *temp_node = *head;
     int value;

     if (*head == NULL)
          return (0);
     (*head) = (*head)->next;
     value = temp_node->n;
     free(temp_node);
     return (value);
}