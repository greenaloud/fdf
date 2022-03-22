#include <stdlib.h>
#include "gnl.h"

int	get_length(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int	check_nl(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int	copy_content(char *dst, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (idx);
}

void	copy_last_content(char *dst, char *src, char *buffer)
{
	int	idx;
	int	pos;

	pos = check_nl(src);
	if (pos != -1)
	{
		idx = 0;
		while (idx <= pos)
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
		idx = 0;
		while (src[pos + 1 + idx])
		{
			buffer[idx] = src[pos + 1 + idx];
			idx++;
		}
		buffer[idx] = '\0';
	}
	else
		copy_content(dst, src);
}

t_piece	*lst_new(char *str)
{
	t_piece	*new;

	new = malloc(sizeof (*new));
	if (new == NULL)
		return (NULL);
	copy_content(new->content, str);
	new->next = NULL;
	return (new);
}
