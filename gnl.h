#ifndef GNL_H
# define GNL_H

# ifndef MAX_OPEN
#  define MAX_OPEN 256
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_piece
{
	char			content[BUFFER_SIZE + 1];
	struct s_piece	*next;
}				t_piece;

char	*get_next_line(int fd);
t_piece	*read_single_line(int fd, char **buffer, int *len);
char	*make_string(t_piece *node, char *buffer, int len);
void	*free_ptr(void **ptr);
int	get_length(char *str);
int	check_nl(char *str);
int	copy_content(char *dst, char *src);
void	copy_last_content(char *dst, char *src, char *buffer);
t_piece	*lst_new(char *str);

#endif
