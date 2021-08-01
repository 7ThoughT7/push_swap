#include "push_swap.h"

void	sa(t_list **a, int i)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;

	list1 = *a;
	list2 = (*a)->next;
	list3 = list2->next;
	list2->next = list1;
	list1->next = list3;
	*a = list2;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, int i)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;

	list1 = *b;
	list2 = (*b)->next;
	list3 = list2->next;
	list2->next = list1;
	list1->next = list3;
	*b = list2;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, int i)
{
	sa(a, 0);
	sb(b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}

void	pa(t_list **a, t_list **b, int i)
{
	t_list *tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, int i)
{
	t_list *tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (i == 1)
		write(1, "pb\n", 3);
}
