#ifndef POINT_H
# define POINT_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
} t_point;

t_point	***str_point_to_points(char ***str_point, int row, int col);

#endif