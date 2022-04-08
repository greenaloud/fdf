CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = fdf

SRCS = main.c \
		gnl.c \
		gnl_util.c\
		error.c \
		free.c \
		read_map.c
OBJS = $(SRCS:.c=.o)

all = $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS) libft.a libmlx.dylib
	$(CC) $(CFLAGS) -o $@ $^ -Lmlx -framework OpenGL -framework AppKit

libft.a:
	make -C libft
	cp libft/libft.a ./

libmlx.dylib:
	make -C mlx
	cp mlx/libmlx.dylib ./

clean:
	make -C mlx clean
	rm -f $(OBJS)

fclean: clean
	rm -f mlx/libmlx.dylib
	rm -f libft.a
	rm -f libmlx.dylib
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re