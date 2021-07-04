#include "push_swap.h"

void	sa(t_list **a)
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
}
