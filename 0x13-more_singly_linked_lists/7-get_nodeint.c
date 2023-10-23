#include "lists.h"

/**
 * get_nodeint_at_index - get address of node at index `index' from `head'
 * @head: pointer to head of list
 * @index: index of list node to return
 *
 * Return: pointer to list node, or NULL if `index' is not present
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
     unsigned int i;

     if (head == NULL)
          return (NULL);
     for (i = 0; i < index; i++)
          head = head->next;
     return (head);
}