#include <stdlib.h>
#include "point.h"

t_point	*create_point(int x, int y, int z)
{
	t_point	*point;

	point = malloc(sizeof(*point));
	if (point == NULL)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}
