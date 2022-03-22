#ifndef GNL_H
# define GNL_H

char	*get_next_line(int fd);
t_list	*read_single_line(int fd, char **buffer, int *len);
char	*make_string(t_list *node, char *buffer, int len);
void	*free_ptr(void **ptr);
int	get_length(char *str);
int	check_nl(char *str);
int	copy_content(char *dst, char *src);
void	copy_last_content(char *dst, char *src, char *buffer);
t_list	*lst_new(char *str);

#endif
