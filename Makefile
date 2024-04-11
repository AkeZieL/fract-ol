NAME = fractol

LIBFT = ./libft/libft.a

MINILIB = ./minilibx-linux/libmlx.a

SRCS = main.c check_error.c fractal.c key.c mouse.c utils.c \
       julia.c mandelbrot.c newton.c get_next_line_bonus.c \
       ft_strjoin2.c utils2.c take_julia_preset.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -lX11 -lXext -lm -g

all: $(NAME)

$(NAME):	$(OBJS)
	make -C ./libft/
	make -C ./minilibx-linux/
	gcc $(SRCS) $(LIBFT) $(MINILIB) $(CFLAGS) -o $(NAME)

$(OBJ_DIR)

clean:
	make clean -C ./libft/
	make clean -C ./minilibx-linux/
	rm -rf $(OBJS)

fclean:	clean
	make fclean -C ./libft/
	rm -rf $(NAME)

re:	fclean all
