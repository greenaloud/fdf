#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include "error.h"
#include "point.h"
#include "read_map.h"
#include "map_to_point.h"

static void	print_double(char **d)
{
	int	i;

	i = 0;
	while (d[i + 1])
	{
		printf("%s ", d[i]);
		i++;
	}
	printf("%s", d[i]);
}

static void	print_triple(char ***t)
{
	int i;

	i = 0;
	while (t[i])
	{
		print_double(t[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int     fd;
	int 	row;
	int 	col;
	char    **lines;
	char	***str_point;
//	t_point ***points;

	if (argc != 2 && argc != 4)
		usage_error();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit("file open error occurred\n");
	lines = read_map(fd, &row);
	str_point = str_map_to_str_point(lines, row, &col);
	print_triple(str_point);
	points = str_point_to_points(str_point, row, col);
	system("leaks fdf");
	return (0);
}

//int	main(int argc, char **argv)
//{
//	logic(argc, argv);
//	system("leaks fdf");
//	return (0);
//}
