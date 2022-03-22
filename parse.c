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


void	parse_map(int fd)
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
//	matrix = points_to_matrix(points);
}
