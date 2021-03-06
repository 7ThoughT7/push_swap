#include "push_swap.h"

void	ra(t_list **a, int i)
{
	t_list	*tmp;

	tmp = *a;
	if (tmp->next == NULL)
		return ;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, int i)
{
	t_list	*tmp;

	tmp = *b;
	if (tmp->next == NULL)
		return ;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int i)
{
	if (*a != NULL)
		ra(a, 0);
	if (*b != NULL)
		rb(b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}

void	rra(t_list **a, int i)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		c;

	tmp2 = *a;
	if (tmp2 == NULL)
		return ;
	c = ft_lstsize(*a);
	tmp = ft_lstlast(*a);
	while ((c - 2) > 0)
	{
		tmp2 = tmp2->next;
		c--;
	}
	tmp2->next = NULL;
	tmp->next = *a;
	*a = tmp;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int i)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		c;

	tmp2 = *b;
	if (tmp2 == NULL)
		return ;
	c = ft_lstsize(*b);
	tmp = ft_lstlast(*b);
	while ((c - 2) > 0)
	{
		tmp2 = tmp2->next;
		c--;
	}
	tmp2->next = NULL;
	tmp->next = *b;
	*b = tmp;
	if (i == 1)
		write(1, "rrb\n", 4);
}
