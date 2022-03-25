#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "gnl.h"
#include "free.h"
#include "error.h"
#include "parse.h"
#include "point.h"
#include "parse2.h"
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

t_list	*map_to_str_list(int fd, int *len)
{
	char	*line;
	t_list	*head;

	line = get_next_line(fd);
	if (line == NULL)
		error_exit();
	*len = 1;
	head = map_to_lines(fd, line, len);
	if (head == NULL)
		error_exit();
	return (head);
}

t_point	***parse_map(int fd)
{
	int 	len;
	t_list	*head;
	t_list	*temp;

	head = map_to_str_list(fd, &len);
	temp = head;
	while (temp)
	{
		printf("%s", temp->content);
		temp = temp->next;
	}
	str_list_to_matrix(&head, len);
	return (NULL);
}
