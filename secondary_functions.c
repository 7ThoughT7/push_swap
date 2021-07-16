#include "push_swap.h"

int nearest_index(t_list **list_a, int index_b)
{
	t_list	*tmp;
	int		index_a;

	tmp = *list_a;
	index_a = tmp->index;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < index_a)
			index_a = tmp->index;
		tmp = tmp->next;
	}
	return (index_a);
}