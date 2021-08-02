#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && s2[i] && i < len)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	if (i != len)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	get_next_line(char **line)
{
	int		i;
	int		res;
	char	ch;
	char	*buf;

	buf = malloc(sizeof(char) * 1025);
	if (!buf)
		return (-1);
	i = 0;
	ch = '\0';
	*line = buf;
	res = 1;
	while (res > 0 && ch != '\n')
	{
		res = read(0, &ch, 1);
		buf[i++] = ch;
	}
	buf[i] = '\0';
	return (res);
}

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
