#include "sort.h"

/**
 * cocktail_sort_list - Sorts a dll using cocktail algo
 * @list: address of pointer to the head of list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp, *head = *list;
	int sorted = 1;

	if (!list || !*list || (*list)->next == NULL)
		return;

/*
*	tmp = head;
*	while (tmp->next)
*		tmp = tmp->next;
*
*	tail = end = tmp;
*	head = start = *list;
*/
	while (sorted)
	{
		tmp = head;
		while (tmp->next != NULL)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_nodes(list, tmp, tmp->next);
				print_list(*list);
				sorted = 0;
			}
			else
			{
				tmp = tmp->next;
			}
		}

		if (sorted)
			break;

		sorted = 1;
		tmp = tmp->prev;
		while (tmp->prev != NULL)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap_nodes(list, tmp->prev, tmp);
				print_list(*list);
				sorted = 0;
			}
			else
			{
				tmp = tmp->prev;
			}
		}
		if (sorted)
			break;
		sorted = 1;
	}
}



/**
 * swap_nodes - swap two successive nodes of a Doubly Linked List
 * @head: pointer to head of linked list
 * @n1: The first node
 * @n2: The second node
 */

void swap_nodes(listint_t **head, listint_t *n1, listint_t *n2)
{
	listint_t *tmp_node;

	if (n1 == NULL || n2 == NULL)
		return;

	tmp_node = n1->prev;

	if (tmp_node)
		tmp_node->next = n2;

	n2->prev = tmp_node;
	n1->next = n2->next;

	if (n2->next)
		n2->next->prev = n1;

	n2->next = n1;
	n1->prev = n2;

	if (!n2->prev)
		(*head) = n2;
}


