#include "sort.h"



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



/**
 * insertion_sort_list - Sorts a listint using insertion algorithm
 * @list: address of pointer to a listint_t structure
 *
 * ALGORITHM: moving from left to right keep swapping values
 * such that that at every point in time, the list on the left
 * is sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list)
		return;

	current = *list;

	while (current != NULL)
	{
		/*			For ascending order			*/
		if (current && current->next && (current->n > current->next->n))
		{
			temp = current->next;
			swap_nodes(list, current, temp);
			if (temp->prev)
				current = temp->prev;
			else
				current = temp;
			print_list(*list);

	/* Keep swapping while there are still lower values on the left hand */
			while (temp && temp->prev && (temp->prev->n > temp->n))
			{
				swap_nodes(list, temp->prev, temp);
				print_list(*list);
			}
		}
		current = current->next;
	}
}
