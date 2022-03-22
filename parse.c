#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "gnl.h"
#include "free.h"
#include "error.h"
#include "parse.h"
#include "point.h"
#include "libft/libft.h"

void	delete_data(void *data)
{
	if (data != NULL)
		free(data);
}

void	*free_node(t_list **del)
{
	free((*del)->content);
	free(*del);
	*del = NULL;
	return (NULL);
}

t_list	*map_to_lines(int fd, char *line, int *count)
{
	t_list	*node;

	node = ft_lstnew(line);
	if (node == NULL)
	{
		free(line);
		return (NULL);
	}
	line = get_next_line(fd);
	if (line)
	{
		(*count)++;
		node->next = map_to_lines(fd, line, count);
		if (node->next == NULL)
			return (free_node(&node));
	}
	return (node);
}

char	***split_lines(t_list **head, int len)
{
	int 	i;
	char	***points;
	t_list	*node;

	points = malloc(sizeof (*points) * (len + 1));
	if (points == NULL)
		error_exit();
	points[len] = NULL;
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

void	parse_z_and_color(int *z, int *color, char *point_str)
{

}

t_point *create_point(int i, int j, char *point_str)
{
	int 	z;
	int 	color;
	t_point	*point;

	parse_z_and_color(&z, &color, point_str);
	point = create_point(i, j, z, color)
}

t_point	**points_to_matrix(char ***points, int row, int col)
{
	int		i;
	int		j;
	t_point	**matrix;

	matrix = malloc(sizeof (*matrix) * row);
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (points[i])
	{
		matrix[i] = malloc(sizeof (**matrix) * col);
		j = 0;
		while (points[i][j])
		{
			matrix[i][j] = create_point(i, j, points[i][j]);
			j++;
		}
		i++;
	}
	return (matrix);
}

t_point	**parse_map(int fd)
{
	int 	len;
	char	*line;
	t_list	*head;
	char	***points;
	t_point	**matrix;

	line = get_next_line(fd);
	if (line == NULL)
		error_exit();
	len = 1;
	head = map_to_lines(fd, line, &len);
	if (head == NULL)
		error_exit();
	points = split_lines(&head, len);
	int	i = 0;
	while (points[i])
	{
		char **temp = points[i];
		while (*temp)
		{
			printf("%s ", *temp);
			temp++;
		}
		printf("\n");
		i++;
	}
	matrix = points_to_matrix(points, row, col);
	return (matrix);
}
