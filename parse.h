#ifndef PARSE_H
# define PARSE_H

# include "point.h"
# include "libft/libft.h"

void	delete_data(void *data);
void	*free_node(t_list **del);
t_list	*map_to_lines(int fd, char *line, int *count);
char	***split_lines(t_list **head, int len);
t_point	***parse_map(int fd);


#endif
