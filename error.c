#include <unistd.h>
#include <stdlib.h>
#include "error.h"
#include "libft/libft.h"

void	error_exit(void)
{
	char	*err_msg;

	err_msg = "Error\n";
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
