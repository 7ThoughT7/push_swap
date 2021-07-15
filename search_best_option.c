#include "push_swap.h"

void	push_BinA(t_list **list_a, t_list **list_b, t_num *num)
{
	int	range_a;
	int range_b;
	int bool_a;
	int bool_b;

	range_a = (*list_a)->num_range;
	range_b = (*list_b)->num_range;
	bool_a = (*list_a)->bool_v;
	bool_b = (*list_b)->bool_v;
	if (bool_a == bool_b)
		rrr_rr(list_a, list_b);
	

}

void	push_list_a(t_list **list_a, t_list **list_b, t_num *num)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *list_a;
	tmp2 = *list_b;
	min_steps(&tmp1, &tmp2, num);
	
}

void	best_way(t_list **list_a, t_list **list_b, t_num *num)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int 	i;
	int 	len;

	tmp1 = *list_a;
	tmp2 = *list_b;
	i = 0;
	while (tmp2)
	{
		len = ft_lstsize(*list_a);
		i = tmp2->index + 1;
		while (len && tmp1->index != i)
		{
			tmp1 = tmp1->next;
			if (tmp1 == 0)
				tmp1 = *list_a;
			len--;
		}
		if (tmp1->index == i)
			tmp2->steps = tmp1->num_range + tmp2->num_range;
		else
			tmp2->steps = 2147483647; //прописать мах инт
		tmp2 = tmp2->next;
	}
//	while (*list_b)
//	{
//		printf("\nvalue:%d ", (*list_b)->value);
//		printf("steps:%d ", (*list_b)->steps);
//		(*list_b) = (*list_b)->next;
//	}
}

void	marking(t_list **list, t_num *num)
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
	while (*list)					/* удалить */
	{
		printf("\nvalue:%d ", (*list)->value);
		printf("num_range:%d ", (*list)->num_range);
		printf("bool:%d ", (*list)->bool_v);
		printf("index:%d", (*list)->index);
		(*list) = (*list)->next;
	}
}

void	search_best_option(t_list **list_a, t_list **list_b, t_num *num)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *list_a;
	tmp2 = *list_b;
	marking(&tmp1, num);
	marking(&tmp2, num);
	best_way(list_a, list_b, num);
	push_list_a(list_a, list_b, num);
}