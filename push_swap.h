#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

#define STACK_ERROR "stack error"

typedef struct s_stack
{
	int				num;
	size_t			index;
	struct s_stack*	next;
}					t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_atoi(const char *s);

void	sa(t_list **a);

# endif