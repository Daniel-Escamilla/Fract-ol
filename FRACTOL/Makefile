SOURCE_PATH = src/
SOURCE_FILES =	ft_fractol.c \
				ft_make_mandel.c \
				ft_make_julia.c \
				ft_make_bonus.c \
				ft_fractol_utils.c \
				ft_pow.c \
				ft_atof.c

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx

MLX_PATH = mlx/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

INC =	-I ./libft/\
		-I ./mlx/\

SOURCES_FILES = $(addprefix $(SOURCE_PATH), $(SOURCE_FILES))

OBJECTS_PATH = objects/
OBJECT = $(SOURCE_FILES:.c=.o)
OBJECTS = $(addprefix $(OBJECTS_PATH), $(OBJECT))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJECTS_PATH)%.o: $(SOURCE_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJECTS): $(OBJECTS_PATH)

$(OBJECTS_PATH):
	@mkdir $(OBJECTS_PATH)

$(MLX):
	@make -sC $(MLX_PATH)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(MLX) $(LIBFT) $(INC) -Lmlx/ -lmlx -framework OpenGL -framework AppKit

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