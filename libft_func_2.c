#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if (*lst)
		{
			free(*lst);
			*lst = NULL;
		}
		*lst = tmp;
	}
}