#include <stdlib.h>
#include <stdio.h>
#include "error.h"
#include "free.h"
#include "parse.h"
#include "parse2.h"
#include "libft/libft.h"

char	***split_lines(t_list **head, int row)
{
	int 	i;
	char	***points;
	t_list	*node;

	points = malloc(sizeof (*points) * (row + 1));
	if (points == NULL)
		error_exit();
	points[row] = NULL;
	i = 0;
	node = *head;
	while (node != NULL)
	{
		points[i] = ft_split(node->content, ' ');
		if (points[i] == NULL)
		{
			while (--i >= 0)
				free_double(points[i]);
			free(points);
			ft_lstclear(head, delete_data);
			error_exit();
		}
		i++;
		node = node->next;
	}
	return (points);
}

t_point	***points_to_matrix(char ***points, int row)
{
	int 	i;
	int 	j;
	t_point	***matrix;

	matrix = malloc(sizeof (*matrix) * (row + 1));
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < row)
	{
//		현재 작성중인 라인
	}
}

t_point	***str_list_to_matrix(t_list **head, int row)
{
	char	***points;
	t_point	***matrix;

	points = split_lines(head, row);
	// head lstclear 필요
	return (NULL);
}
