#include <stdlib.h>
#include "read_map.h"
#include "error.h"
#include "gnl.h"

static t_ml    *create_ml(char *str)
{
	t_ml    *new_ml;

	new_ml = malloc(sizeof (*new_ml));
	if (new_ml == NULL)
		return (NULL);
	new_ml->line = str;
	new_ml->next = NULL;
	return (new_ml);
}

static char	**ml_to_arr(t_ml *head, int cnt)
{
	int 	i;
	t_ml	*del;
	char	**str_map;

	str_map = malloc(sizeof (*str_map) * (cnt + 1));
	if (str_map == NULL)
		read_error(head);
	i = 0;
	while (head != NULL)
	{
		str_map[i++] = head->line;
		del = head;
		head = head->next;
		free(del);
	}
	str_map[i] = NULL;
	return (str_map);
}

char    **read_map(int fd, int *row)
{
	int		cnt;
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
	if (cnt == 0)
		error_exit("empty file\n");
	*row = cnt;
	return (ml_to_arr(dummy.next, cnt));
}
