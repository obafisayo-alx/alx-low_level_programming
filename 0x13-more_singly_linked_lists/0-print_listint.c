#include "lists.h"

size_t print_listint(const listint_t *h)
{
     size_t j;
     
     for (j = 0; h != NULL; ++j)
     {
          printf("%d\n", h->n);
          h = h->next;
     }
     return (j);
}
