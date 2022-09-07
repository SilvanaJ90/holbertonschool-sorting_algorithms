#include "sort.h"

/**
 * sortedInsert - check code
 * @list: double pointer de list
 * @newNode: node
 */

void sortedInsert(listint_t **list, listint_t *newNode)
{
	listint_t *current;

	if (*list == NULL)
	*list = newNode;

	else if ((*list)->n >= newNode->n)
	{
		newNode->next = *list;
		newNode->next->prev = newNode;
		*list = newNode;
	}
	else
	{
		current = *list;
		while (current->next != NULL && current->next->n < newNode->n)
			current = current->next;
	newNode->next = current->next;
	if (current->next != NULL)
		newNode->next->prev = newNode;
	current->next = newNode;
	newNode->prev = current;
	}
}



/**
 * insertion_sort_list - check code
 * @list: doble pointer lista
 */

void insertion_sort_list(listint_t **list)
{
	/* Initialize 'sorted' - a sorted doubly linked list */
	listint_t *sorted = NULL;

	/* Traverse the given doubly linked list and */
    /* insert every node to 'sorted */
	listint_t *current = NULL;

	current = *list;

	while (current != NULL)
	{
		/* Store next for next iteration */
		listint_t *next = current->next;

		/* removing all the links so as to create 'current' */
		current->prev = current->next = NULL;

		/* insert current in 'sorted' doubly linked list */
		sortedInsert(&sorted, current);

		/* Update current */
		current = next;
	}
	*list = sorted;
	return;
}
