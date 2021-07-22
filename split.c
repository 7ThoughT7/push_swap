#include "push_swap.h"

static int	frst_mem(char *s, char c)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || s[i + 1] == '\0')
		{
			tmp++;
			i++;
		}
		else
			i++;
	}
	return (tmp);
}

static char	**two_mem(char **str, char *s, char c)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				len++;
				i++;
			}
			str[j] = malloc(sizeof(char) * (len + 1));
			if (!str[j])
				return (NULL);
			j++;
		}
		else
			i++;
	}
	return (str);
}

static char	**filling(char **str, char *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			while (s[i] != c && s[i])
				str[j][k++] = s[i++];
			str[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (frst_mem(s, c) + 1));
	if (!str)
		return (NULL);
	if (!two_mem(str, s, c))
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
		return (NULL);
	}
	filling(str, s, c);
	return (str);
}
