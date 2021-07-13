#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define STACK_ERROR "stack error"

typedef struct s_stack
{
	int				value;
	int 			index;
	int 			bool_v;
	int 			num_range;
	struct s_stack*	next;
}					t_list;

typedef struct s_num_val
{
	int	count;
	int	value;
	int step;
	int len_list;
	int val_ran;
	int	max_num_range;
}		t_num;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_atoi(const char *s);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnum(t_list *lst, t_num num);
void	zero_bool_list(t_list **list);


void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	indexation(t_list **list, t_num *num);
void 	search_max_range(t_list **list, t_num *num);
void	best_index(t_list **list, t_num num);
void	max_range(t_list **list, t_num *num);
void	push_list_b(t_list **list_a, t_list **list_b, t_num *num);
void	search_start(t_list **list, t_num *num);

# endif