SOURCE_PATH = src/
SOURCE_FILES =	ft_atof.c \
				ft_fractol_utils.c \
				ft_fractol.c \
				ft_make_julia.c \
				ft_make_mandel.c \
				ft_mouse.c \
				ft_pow.c \
				ft_values.c \
				ft_make_newton_bonus.c 

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -g3

MLX_PATH = mlx_linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

INC =	-I ./libft/\
		-I ./mlx_linux/\

SOURCES_FILES = $(addprefix $(SOURCE_PATH), $(SOURCE_FILES))

OBJECTS_PATH = objects/
OBJECT = $(SOURCE_FILES:.c=.o)
OBJECTS = $(addprefix $(OBJECTS_PATH), $(OBJECT))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJECTS_PATH)%.o: $(SOURCE_PATH)%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(OBJECTS): $(OBJECTS_PATH)

$(OBJECTS_PATH):
	@mkdir $(OBJECTS_PATH)

$(MLX):
	@make -sC $(MLX_PATH)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME) -Llibft/ -lft -lm -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11  -lz

bonus: all

clean:
	rm -rf $(OBJECTS_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_PATH)

re: fclean all

.PHONY: re fclean clean all