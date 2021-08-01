#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int get_next_line(char **line)
{
	char *buf;
	int i;
	int res;
	char ch;

	buf = malloc(sizeof(char) * 1025);
	if (!buf)
		return (-1);
	i = 0;
	ch = '\0';
	*line = buf;
	while ((res = read(0, &ch, 1)) > 0 && ch != '\n')
		buf[i++] = ch;
	buf[i] = '\0';
	return (res);
}