#include <stdlib.h>
#include "free.h"
#include "read_map.h"

void	free_double(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_triple(char ***list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free_double(list[i]);
		i++;
	}
	free(list);
}

void	free_ml(t_ml *head)
{
	t_ml	*del;

	while (head != NULL)
	{
		del = head;
		head = head->next;
		free(del);
	}
}

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
