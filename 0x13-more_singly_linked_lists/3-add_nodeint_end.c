#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - append a new node at end of list pointed to by `head'
 * @head: pointer to pointer to beginning of list
 * @n: value with which to initialize new node
 *
 * Return: address of new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
     listint_t *temp_node, *prev_node = *head;

     temp_node = malloc(sizeof(listint_t));
     if (temp_node == NULL)
          return (NULL);
     temp_node->n = n;
     temp_node->next = NULL;
     if (prev_node == NULL)
     {
          *head = temp_node;
          return (temp_node);
     }
     while (prev_node->next)
          prev_node = prev_node->next;
     prev_node->next = temp_node;
     return (temp_node);
}