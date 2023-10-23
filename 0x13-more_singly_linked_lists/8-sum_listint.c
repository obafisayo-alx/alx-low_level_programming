#include "lists.h"
/**
 * sum_listint - This is the sum of all data contained by nodes of list `head'
 * @head: pointer to beginning of list of type listint_t
 *
 * Return: Sum of list, or 0 if list is empty ar NULL
 */
int sum_listint(listint_t *head)
{
     int sum = 0;

     if (head == NULL)
          return (0);
     while (head != NULL)
     {
          sum += head->n;
          head = head->next;
     }
     return (sum);
}