#ifndef ERROR_H
# define ERROR_H

# include "read_map.h"

void	error_exit(char *err_msg);
void	usage_error(void);
void    read_error(t_ml *head);
void    read_error_str(char **map);
void    read_error_str_arr(char ***arr);

#endif
