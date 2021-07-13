#include "push_swap.h"

void	search_max_range(t_list **list, t_num *num)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		count;
	int		len;

	tmp = *list;
	while (tmp)
	{
		tmp2 = tmp;
		count = 1;
		len = num->len_list;
		num->value = tmp->value;
		while (len-- > 0)
		{
			if (num->value < tmp2->value && count++)
				num->value = tmp2->value;
			tmp2 = tmp2->next;
			if (tmp2 == 0)
				tmp2 = *list;
		}
		tmp->num_range = count;
		tmp = tmp->next;
	}
}

//void	best_index(t_list **list, t_num num)
//{
//	t_list	*tmp;
//	t_list	*tmp2;
//	int		count;
//	int		len;
//
//	tmp = *list;
//	while (tmp)
//	{
//		tmp2 = tmp;
//		count = 1;
//		len = num.len_list;
//		num.value = tmp->index;
//		while (len-- > 0)
//		{
//			if ((num.value + 1) == tmp2->index && count++)
//				num.value = tmp2->index;
//			tmp2 = tmp2->next;
//			if (tmp2 == 0)
//				tmp2 = *list;
//		}
//		tmp->max_num_range = count;
//		tmp = tmp->next;
//	}
//}

void	max_range(t_list **list, t_num *num)
{
	t_list *tmp;

	tmp = *list;
	num->max_num_range = tmp->num_range;
	num->val_ran = tmp->value;
	while (tmp)
	{
		if (num->max_num_range < tmp->num_range)
		{
			num->max_num_range = tmp->num_range;
			num->val_ran = tmp->value;
		}
		if (num->max_num_range == tmp->num_range)
		{
			if (num->val_ran > tmp->value)
				num->val_ran = tmp->value;
		}
		tmp = tmp->next;
	}
}

void	search_start(t_list **list, t_num *num)
{
	int	len;
	t_list *tmp;

	tmp = *list;
	len = num->len_list;
	while (*list)
	{
		if ((*list)->value == num->val_ran && (*list)->num_range == num
		->max_num_range)
			break;
		*list = (*list)->next;
	}
	num->count = (*list)->value;
	(*list)->bool_v = 1;
	while (len--)
	{
		if (num->count < (*list)->value)
		{
			(*list)->bool_v = 1;
			num->count = (*list)->value;
		}
		*list = (*list)->next;
		if ((*list) == 0)
			(*list) = tmp;
	}
}

void	push_b(t_list **list_a, t_list **list_b, t_num *num)
{
	int	len;
//	t_list	*tmp1;
//	t_list	*tmp2;
//
//	tmp1 = *list_a;
//	tmp2 = *list_b;
	len = num->len_list;
	while (len--)
	{
		if ((*list_a)->bool_v == 1)
			ra(list_a);
		else
			pb(list_a, list_b);
	}
//	tmp1 = *list_a;
//	tmp2 = *list_b;
}

void	push_list_b(t_list **list_a, t_list **list_b, t_num *num)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *list_a;
	max_range(&tmp, num);
	tmp2 = *list_a;
	zero_bool_list(&tmp2);
	search_start(&tmp2, num);
	push_b (list_a,list_b, num);
//	while (*list_a)					/* удалить */
//	{
//		printf("\na:%d", (*list_a)->value);
//		(*list_a) = (*list_a)->next;
//	}
//	while (*list_b)					/* удалить */
//	{
//		printf("\nb:%d", (*list_b)->value);
//		(*list_b) = (*list_b)->next;
//	}
	search_best_option(list_a, list_b, num);
}