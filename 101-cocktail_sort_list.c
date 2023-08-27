#include "sort.h"
/**
 *swap_nodes - swap nodes in a doubly linked list
 *@node_1: first node
 *@node_2: second node
 *@list: doubly linked list
 *Return : void
 */
void swap_nodes(listint_t *node_1, listint_t *node_2, listint_t **list)
{
	listint_t *prev, *next;

	prev = node_1->prev;
	next = node_2->next;
	if (prev != NULL)
	{
		prev->next = node_2;
	}
	else
	{
		*list = node_2;
	}
	if (next != NULL)
	{
		next->prev = node_1;
	}
	node_1->prev = node_2;
	node_1->next = next;
	node_2->prev = prev;
	node_2->next = node_1;
}
/**
 *cocktail_sort_list - sort doubly linked list
 *@list: linked list
 *Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *tail;
	int flag = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	tail = NULL;
	while (flag == 1)
	{
		flag = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next, list);
				print_list(*list);
				flag = 1;
			}
			else
				current = current->next;
		}
		if (flag == 0)
			break;
		tail = current;
		flag = 0;
		while (tail->prev != NULL)
		{
			if (tail->n < tail->prev->n)
			{
				swap_nodes(tail->prev, tail, list);
				print_list(*list);
				flag = 1;
			}
			else
				tail = tail->prev;
		}
		current = tail;
	}
}
