#include "push_swap.h"

void	push_BinA(t_list **list_a, t_list **list_b, t_num *num)
{
	if (num->bool_a == num->bool_b)
	{
		rrr_rr(list_a, list_b, num);
		rab_or_rrab(list_a, list_b, num);
	}
	else
	{
		ra_or_rra(list_a, num);
		rb_or_rrb(list_b, num);
	}
	pa(list_a, list_b);
}

void	best_way(t_list **list_a, t_list **list_b, t_num *num)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int 	index;
	int 	len;

	tmp1 = *list_a;
	tmp2 = *list_b;
	index = 0;
	while (tmp2)
	{
		len = ft_lstsize(*list_a);
		index = nearest_index(list_a, num, tmp2->index);
		while (len && tmp1->index != index)
		{
			tmp1 = tmp1->next;
			if (tmp1 == 0)
				tmp1 = *list_a;
			len--;
		}
		tmp2->steps = tmp1->num_range + tmp2->num_range;
		tmp2 = tmp2->next;
	}
//	while (*list_b)   /* удалить */
//	{
//		printf("\nvalue:%d ", (*list_b)->value);
//		printf("steps:%d ", (*list_b)->steps);
//		(*list_b) = (*list_b)->next;
//	}
}

void	marking(t_list **list)
{
	int len;
	int	i;
	t_list	*tmp;

	i = 1;
	tmp = *list;
	len = ft_lstsize(tmp);
	zero_bool_list(&tmp);
	zero_range_list(&tmp);
	while (i <= (len / 2 + len % 2))
	{
		tmp->bool_v = 1;
		tmp->num_range = i++;
		tmp = tmp->next;
	}
	if (len % 2 == 1)
		i--;
	while (tmp)
	{
		tmp->num_range = i--;
		tmp = tmp->next;
	}
//	while (*list)					/* удалить */
//	{
//		printf("\nvalue:%d ", (*list)->value);
//		printf("num_range:%d ", (*list)->num_range);
//		printf("bool:%d ", (*list)->bool_v);

//		printf("index:%d", (*list)->index);
//		(*list) = (*list)->next;
//	}
}

void	search_best_option(t_list **list_a, t_list **list_b, t_num *num)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *list_a;
	tmp2 = *list_b;
	while ((*list_b) != NULL)
	{
		marking(list_a);
		marking(list_b);
		best_way(list_a, list_b, num);
		min_steps(list_a, list_b, num);
		push_BinA(list_a, list_b, num);
	}
}
