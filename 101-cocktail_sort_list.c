#include "sort.h"

void swap_nodes(listint_t *nodeA, listint_t *nodeB, listint_t **head);
void cocktail_sort_list(listint_t **list);

/**
 * cocktail_sort_list - function that sorts a doubly linked list  of integers
 * in ascendimng order using cocktail shaker sort
 * @list: doubly linked list to be sorted
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *first = NULL;
	listint_t *last = NULL;


	if (!list || !(*list) || (*list)->next == NULL)
	{
		return;
	}

	current = *list;
	do {
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current->next, current, list);
			}
			else
			{
				current = current->next;
			}
		}
		last = current;
		while (current->prev != first)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current, current->prev, list);
			}
			else
			{
				current = current->prev;
			}
		}
		first = current;
	} while (first != last);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @nodeA: First node to be swapped.
 * @nodeB: Second node to be swapped.
 * @head: Pointer to a pointer to the head of the list.
 */
void swap_nodes(listint_t *nodeA, listint_t *nodeB, listint_t **head)
{
	listint_t *swap_1 = nodeA->next;
	listint_t *swap_2 = nodeB->prev;

	if (swap_1 != NULL)
	{
		swap_1->prev = nodeB;
	}

	if (swap_2 != NULL)
	{
		swap_2->next = nodeA;
	}

	nodeA->prev = swap_2;
	nodeB->next = swap_1;
	nodeA->next = nodeB;
	nodeB->prev = nodeA;

	if (*head == nodeB)
	{
		*head = nodeA;
	}
	print_list(*head);
}
