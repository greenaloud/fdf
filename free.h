#ifndef FREE_H
# define FREE_H

# include "read_map.h"

void	free_double(char **ptr);
void	free_triple(char ***list);
void	free_ml(t_ml *head);
void	free_double_point(t_point **points);
void	free_triple_point(t_point ***points);

#endif
