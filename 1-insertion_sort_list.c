#include "sort.h"
/**
 *insertion_sort_list - sort list of ints in asc ord by Insertion sort algo
 *@list: doubly linked list
 *Return : void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node;
	listint_t *old_node;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current_node = (*list)->next;
	while (current_node != NULL)
	{
		old_node = current_node;
		while (old_node->prev)
		{
			temp = old_node->prev;
			if (old_node->n < temp->n)
			{
				temp->next = old_node->next;
				old_node->prev = temp->prev;
				if (old_node->next)
					old_node->next->prev = temp;
				if (temp->prev)
					temp->prev->next = old_node;
				else
					*list = old_node;
				old_node->next = temp;
				temp->prev = old_node;
				print_list(*list);
				continue;
			}
			old_node = old_node->prev;
		}
		current_node = current_node->next;
	}
}
