#include "sort.h"

size_t get_list_length(listint_t *head)
{

	size_t length = 0;

	while (head)
	{
		length++;
		head = head->next;
	}
	return length;
}

void node_switch(listint_t **head, listint_t **current_node)
{
	listint_t *previous_node, *current, *next_node, *next_next_node;

	previous_node = (*current_node)->prev;
	current = *current_node;
	next_node = (*current_node)->next;
	next_next_node = next_node ? next_node->next : NULL;

	current->next = next_next_node;

	if (next_next_node)
		next_next_node->prev = current;

	next_node->next = current;
	next_node->prev = previous_node;

	if (previous_node)
		previous_node->next = next_node;
	else
		*head = next_node;

	current->prev = next_node;
	*current_node = next_node;
}

void cocktail_sort_list(listint_t **list)
{
	listint_t *current_node;
	int is_sorted = 0;

	if (!list || !*list || get_list_length(*list) < 2)
		return;

	current_node = *list;
	while (!is_sorted)
	{
		is_sorted = 1;
		while (current_node->next)
		{
			if (current_node->n > current_node->next->n)
			{
				is_sorted = 0;
				node_switch(list, &current_node);
				print_list(*list);
			}
			else
			{
				current_node = current_node->next;
			}
		}
		if (is_sorted)
			break;
		current_node = current_node->prev;
		while (current_node->prev)
		{
			if (current_node->n < current_node->prev->n)
			{
				is_sorted = 0;
				current_node = current_node->prev;
				node_switch(list, &current_node);
				print_list(*list);
			}
			else
				current_node = current_node->prev;
		}
	}
}
