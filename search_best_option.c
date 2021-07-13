#include "push_swap.h"

void	best_way(t_list **list_a, t_list **list_b, t_num *num)
{
	t_list	*tmp1;
	t_list	*tmp2;


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

}