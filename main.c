#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include "error.h"
#include "read_map.h"

int	main(int argc, char **argv)
{
	int     fd;
    char    **lines;

	if (argc != 2 && argc != 4)
		usage_error();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit();
    lines = read_map(fd);
	return (0);
}
