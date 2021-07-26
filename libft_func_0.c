#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst == NULL)
		return (lst);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
		}
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
//	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
//		i++;
//	else if (s[i] == '+')
//		i++;
	while (s[i])
	{
		if (s[i] == '-')
		{
			sign *= -1;
			i++;
		}
		if (ft_isdigit(s[i]) == 1)
		{
			n = (n * 10) + (s[i++] - 48);
			if ((n * sign) < -2147483648)
				return (0);
			if ((n * sign) > 2147483647)
				return (-1);
		}
	}
	return (n * sign);
}
