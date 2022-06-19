#include <stdlib.h>
#include "point.h"
#include "free.h"
#include "error.h"
#include "libft/libft.h"

static t_point	***init_points(char ***str_point, int row, int col)
{
	int		i;
	char	***points;

	points = malloc(sizeof (*points) * (row + 1));
	if (points == NULL)
	{
		free_triple(str_point);
		error_exit("Error while mapping map file to point array\n");
	}
	points[row] = NULL;
	i = 0;
	while (i < row)
	{
		points[i] = malloc(sizeof (**points) * (col + 1));
		if (points[i] == NULL)
		{
			free_triple(str_point);
			free_triple_point(points);
			error_exit("Error while mapping map file to point array\n");
		}
		i++;
	}
	return (points);
}

static int parse_color(char *str)
{
	int i;
	int len;
	int	color;

	len = ft_strlen(str);
	i = len - 1;
	while (i >= 2)
	{
		if (48 <= str[i] && str[i] <= 57)
			color |= (str[i] - '0') << (len - i);
		else if (97 <= str[i] && str[i] <= 102)
			color |= (str[i] - 'a' + 10) << (len - i);
	}
	return (color);
}

static t_point	*create_point(int x, int y, int z, int color)
{
	t_point *point;

	point = malloc(sizeof (point));
	if (point == NULL)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = color;
	return (point);
}

static t_point	*convert_point(char *str_point, int x, int y)
{
	int 	z;
	int 	color;
	char	**result;
	t_point *point;

	result = ft_split(str, ',', &count);
//	if (count > 2)
	z = ft_atoi(result[0]);
	color = 255 << 16 | 255 << 8 | 255;
	if (result[1])
		color = parse_color(result[1]);
	point = create_point(x, y, z, color);
//	if (point == NULL)
	return (point);
}

t_point	***str_point_to_points(char ***str_point, int row, int col)
{
	int 	i;
	int 	j;
	t_point	***points;

	points = init_points(str_point, row, col);
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			points[i][j] = convert_point(str_point[i][j], i, j);
			j++;
		}
		i++;
	}
	return (points);
}
