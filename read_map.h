#ifndef READ_MAP_H
# define READ_MAP_H

typedef struct s_ml
{
    char		*line;
    struct s_ml	*next;
} t_ml;

char    **read_map(int fd, int *row);

#endif
