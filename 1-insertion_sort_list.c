#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: A double pointer to the head of the doubly linked list.
 *
 * Description:
 * This function takes a double pointer to the head of a doubly linked list of
 * integers and sorts the list in ascending order using the Insertion Sort
 * algorithm. The algorithm iterates through the list, considering one element
 * at a time and inserting it at the correct position within the sorted part of
 * the list, resulting in a sorted list when all elements are processed.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current->prev;
			current->prev = temp->prev;
			temp->next = current->next;

			if (current->next != NULL)
				current->next->prev = temp;

			current->next = temp;

			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;

			temp->prev = current;
			print_list(*list);
		}
		current = current->next;
	}
}
