#include <stdlib.h>
#include "read_map.h"
#include "error.h"
#include "free.h"
#include "gnl.h"

t_ml    *create_ml(char *str)
{
	t_ml    *new_ml;

	new_ml = malloc(sizeof (*new_ml));
	if (new_ml == NULL)
		return (NULL);
	new_ml->line = str;
	new_ml->next = NULL;
	return (new_ml);
}

char    **read_map(int fd)
{
	int		cnt;
	char	**str_map;
	char	*line;
	t_ml	dummy;
	t_ml	*cur;

	cnt = 0;
	cur = &dummy;
	dummy.next = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		cur->next = create_ml(line);
		if (cur->next == NULL)
			read_error(dummy.next);
		cnt++;
		line = get_next_line(fd);
		cur = cur->next;
	}
	str_map = malloc(sizeof (*str_map) * (cnt + 1));
	cnt = 0;
	cur = dummy.next;
	while (cur != NULL)
	{
		str_map[cnt++] = cur->line;
		cur = cur->next;
	}
	str_map[cnt] = NULL;
	free_ml(dummy.next);
	return (str_map);
}
