#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	write(1, "ra\n", 3); //удалить
}

void	rb(t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
	write(1, "rb\n", 3); //удалить

}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	ra(b);
	write(1, "rr\n", 3); //удалить

}

void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		c;

	tmp2 = *a;
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
	write(1, "rra\n", 4); //удалить
}

void	rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		c;

	tmp2 = *b;
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
	write(1, "rrb\n", 4); //удалить
}
