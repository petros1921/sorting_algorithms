#include "sort.h"

void node_swap(listint_t *a1, listint_t *a2)
{
	if (a1->prev)
		a1->prev->next = a2;
	if (a2->next)
		a2->next->prev = a1;
	a1->next = a2->next;
	a2->prev = a1->prev;
	a1->prev = a2;
	a2->next = a1;

}
void insertion_sort_list(listint_t **list)
{
	listint_t *len, *tmp;

	if (!list || !*list || !(*list)->next)
		return;
	len = (*list)->next;
	while (len)
	{
		tmp = len;
		len = len->next;
		while (tmp && tmp->prev)
		{
			if (tmp->prev->n > tmp->n)
			{
				node_swap(tmp->prev, tmp);
				if (!tmp->prev)
					*list = tmp;
				print_list((const listint_t *)*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
