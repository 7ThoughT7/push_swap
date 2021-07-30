#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack
{
	int			value;
	int 			index;
	int 			bool_v;
	int				steps;
	int 			num_range;
	struct s_stack*	next;
}					t_list;

typedef struct s_num_val
{
	int	count;
	int	value;
	int len_list;
	int index_a;
	int index_b;
	int	step_a;
	int step_b;
	int bool_a;
	int bool_b;
	int val_ran;
	int	max_range;
	char **str;
}		t_num;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int 	ft_atoi(const char *s);
int		ft_lstsize(t_list *lst);
void	zero_bool_list(t_list **list);
void	zero_range_list(t_list **list);
void	min_steps(t_list **list_a, t_list **list_b, t_num *num);
int		min_r(int a, int b);
char	**ft_split(char const *s, char c);
void	ft_lstclear(t_list **lst);
int		ft_isdigit(int c);
void	error(void);
//char	*ft_strchr(const char *s, int c);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a, int i);
void	rb(t_list **b, int i);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a, int i);
void	rrb(t_list **b, int i);
void	rrr(t_list **a, t_list **b);
void	rrr_rr(t_list **list_a, t_list **list_b, t_num *num);
void	rab_or_rrab(t_list **list_a, t_list **list_b, t_num *num);
void	ra_or_rra(t_list **list_a, t_num *num);
void	rb_or_rrb(t_list **list_b, t_num *num);

void	indexation(t_list **list, t_num *num);
void 	search_max_range(t_list **list, t_num *num);
void	max_range(t_list **list, t_num *num);
void	push_list_b(t_list **list_a, t_list **list_b, t_num *num);
void	search_start(t_list **list, t_num *num);
void	marking(t_list **list);
void	search_best_option(t_list **list_a, t_list **list_b, t_num *num);
int		nearest_index(t_list **list_a, t_num *num, int index_b);
void	stack_scrolling(t_list **list, t_num *num);
void	sorting_3(t_list **a);
void	filling_a(char **str, t_list **a);
void	parser(t_list **a, t_list *list);
void	push_in_b_for4(t_list **a, t_list **b, t_num *num);
void	push_in_b_for5(t_list **a, t_list **b, t_num *num);

# endif