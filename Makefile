CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = fdf

SRCS = main.c \
#		gnl.c \
#		gnl_util.c\
#		point.c
OBJS = $(SRCS:.c=.o)

all = $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS) libmlx.dylib
	$(CC) $(CFLAGS) -o $@ $^ -Lmlx -framework OpenGL -framework AppKit

libmlx.dylib:
	make -C mlx
	cp mlx/libmlx.dylib ./

clean:
	make -C mlx clean
	rm -f $(OBJS)

fclean: clean
	rm -f mlx/libmlx.dylib
	rm -f libmlx.dylib
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re