#include <stdlib.h>
#include "point.h"
#include "free.h"
#include "error.h"

void	free_double_point(t_point **points)
{
	int	i;

	i = 0;
	while (points[i])
	{
		free(points[i]);
		i++;
	}
	free(points);
}

void	free_triple_point(t_point ***points)
{
	int i;

	i = 0;
	while (points[i])
	{
		free(points[i]);
		i++;
	}
	free(points);
}

t_point	***init_points(char ***str_point, int row, int col)
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

t_point	*convert_point(char *str_point, int x, int y)
{
	int z;
	int color;
	int flag;


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

		}
	}
}
