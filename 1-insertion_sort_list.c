#include "sort.h"

/**
 * insertion_sort_list - check code
 * @list: doble pointer lista
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *swap = NULL, *prev = NULL;

	if (list == NULL)
		return;

	current = *list;
	while ((current = current->next))
	{
		swap = current;
		while (swap->prev && swap->n < swap->prev->n)
		{
			prev = swap->prev;
			if (swap->next)
				swap->next->prev = prev;
			if (prev->prev)
				prev->prev->next = swap;
			else
				*list = swap;
			prev->next = swap->next;
			swap->prev = prev->prev;
			swap->next = prev;
			prev->prev = swap;

			print_list(*list);
		}
	}
}
