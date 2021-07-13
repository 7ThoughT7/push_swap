#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	zero_bool_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (*list)
	{
		(*list)->bool_v = 0;
		*list = (*list)->next;
	}
	if ((*list) == 0)
		*list = tmp;
}

void	zero_range_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (*list)
	{
		(*list)->num_range = 0;
		*list = (*list)->next;
	}
	if ((*list) == 0)
		*list = tmp;
}