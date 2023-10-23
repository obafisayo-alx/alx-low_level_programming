#include "lists.h"
#include <stdlib.h>

listint_t *add_nodeint(listint_t **head, const int n)
{
     listint_t *temp_node;

     temp_node = malloc(sizeof(listint_t));
     if (temp_node = NULL)
          return (NULL);
     temp_node->n = n;
     temp_node->next = *head;
     *head = temp_node;
     return (temp_node);
}