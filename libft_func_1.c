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

t_list	*ft_lstnum(t_list *lst, t_num num)
{
	t_list	*tmp;
	int		len;

	tmp = lst;
	if (lst == NULL)
		return (lst);
	len = num.step;
	while (len > 0)
	{
		tmp = tmp->next;
		len--;
	}
	return (tmp);
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