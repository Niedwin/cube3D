NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = minilibx-linux
LIBFT_DIR = Libft

SRC =	src/main.c \
		src/event.c \
		src/player.c \
		src/movement.c \
		src/rotate.c \
		src/raycast.c \
		src/raycast_utils.c \
		src/utils.c \
		src/utils_kerloye.c \
		src/parsing/fill_textures.c \
		src/parsing/fill_textures_kerloye.c \
		src/initialize.c \
		src/check_n_fill_colors.c \
		src/parsing/parser3.c \
		src/parsing/parsers.c \
		src/free.c \
		src/free2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) -I$(MLX_DIR) -L$(MLX_DIR) -lmlx \
		-L/usr/lib -lXext -lX11 -lm -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
