#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

void sortedInsert(listint_t **list, listint_t *newNode)
{
	listint_t * current;

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
    listint_t *current = *list;

	while(current != NULL)
	{
		/* Store next for next iteration */
		listint_t *next = current->next;

		/* removing all the links so as to create 'current' */
        /* as a new node for insertion */
		current->prev = current->next = NULL;

		/* insert current in 'sorted' doubly linked list */
		sortedInsert(&sorted, current);

		/* Update current */
		current = next;
	}
	*list = sorted;
}
