#include <stdio.h>

#include <stdlib.h>
#include "error.h"
#include "free.h"
#include "map_to_point.h"
#include "libft/libft.h"

static int	get_count(char const *s, char c)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		while (s[idx] == c)
			idx++;
		if (s[idx])
			cnt++;
		while (s[idx] != 0 && s[idx] != c)
			idx++;
	}
	return (cnt);
}

static char	***map_to_point(char **map, int row, int *col)
{
	int		i;
	int 	cnt;
	int 	correct;
	char	***point;

	point = malloc(sizeof (*point) * (row + 1));
	if (point == NULL)
		read_error_str(map);
	correct = get_count(map[0], ' ');
	if (correct == 0)
		error_exit("file content error!\n");
	i = 0;
	while (map[i])
	{
		point[i] = ft_split(map[i], ' ', &cnt);
		if (point[i] == NULL)
		{
			free_double(map);
			read_error_str_arr(point);
		}
		if (cnt != correct)
		{
			free_double(map);
			free_triple(point);
			error_exit("map file column count doesn't match\n");
		}
		i++;
	}
	point[i] = NULL;
	*col = cnt;
	free_double(map);
	return (point);
}

char	***str_map_to_str_point(char **str_map, int	row, int *col)
{
	return (map_to_point(str_map, row, col));
}
