#include "lists.h"
/**
 * print_list - prints all the elements of a list_t list.
 * @h: struct called h
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	int i = 0;
	const list_t *current = h;

	if (h == NULL)
		return (0);

	while (current != NULL)
	{
		if (current->str == NULL)
		{
			printf("[%d] %s\n", 0, "(nil)");
		}
		else
		{
			printf("[%d] %s\n", current->len, current->str);
		}
		current = current->next;
		i++;
	}

	return (i);
}
