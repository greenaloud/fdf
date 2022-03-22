#include "gnl.h"
#include "parse.h"
#include "point.h"
#include "fcntl.h"

static void	error_exit(char *str)
{
	return ;
}

int check_valid(char *line)
{
	int count;

	count = 0;
	while (*line)
	{
		if (*line == '+' or *line == '-')
			line++;
		if ('0' <= *line && *line <= '9')
			count++;
		while ('0' <= *line && *line <= '9')
			line++;
		if (*line == ' ')
			line++;
		if (*line == '\0' || *line == '\n')
			break ;
		if (*line != '+' && *line != '-' && !('0' <= *line && *line <= '9'))
			return (-1);
	}
	return (count);
}

t_point	create_matrix(char *path)
{
	int 	fd;
	int 	row
	int 	col;
	char	*line;
	t_point	**matrix;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit("open");
	line = get_next_line(fd);
	col = check_valid(line);
}

int	**parse_map(char *path)
{
	t_point	**matrix;

	matrix = create_matrix(path);
}
