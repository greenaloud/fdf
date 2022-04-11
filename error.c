#include <unistd.h>
#include <stdlib.h>
#include "error.h"
#include "free.h"
#include "libft/libft.h"
#include "read_map.h"

void	error_exit(char *err_msg)
{
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}

void	usage_error(void)
{
	char	*err_msg;

	err_msg = "Usage: ./fdf <filename> [case_size z_size]\n";
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}

void    read_error_str(char **map)
{
	char    *err_msg;

	free_double(map);
	err_msg = "Error occurred while reading map file\n";
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
}

void    read_error_str_arr(char ***arr)
{
	char    *err_msg;

	free_triple(arr);
	err_msg = "Error occurred while reading map file\n";
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
}

void    read_error(t_ml *head)
{
	char    *err_msg;
	t_ml    *del;

	while (head != NULL)
	{
		free(head->line);
		del = head;
		head = head->next;
		free(del);
	}
	err_msg = "Error occurred while reading map file\n";
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
}
