NAME = cub3D
SRCS = src/main.c \
			src/fill_colors.c \
			src/fill_texture.c \
			src/initialize.c \
			src/parsers.c \
			src/utils.c \

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -L./Libft -lft -lreadline
MMLX = -Lminilibx-linux -lmlx -lXext -lX11 
 
BONUS_FILES =

OBJS = $(SRCS:.c=.o)

all: libft mlx $(NAME)
	@echo "\033[1;93m [WAIT] \033[0m\t\033[1;35mBuilding cube3D...\033[0m" 

libft:
	@make -C Libft --no-print-directory

mlx:
	@make -C minilibx-linux 

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MMLX) -o $(NAME)
	@echo "\033[1;32m [OK]   \033[0m\t\033[1;35mcube3D built successfully!\033[0m"

%.o: %.c
	@echo "\033[1;90m [COMPILE] \033[0m $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C Libft clean --no-print-directory
	@make -C minilibx-linux clean --no-print-directory
	@echo "\033[1;34m [CLEAN] \033[0m Object files removed."

fclean: clean
	@rm -f $(NAME)
	@make -C Libft fclean --no-print-directory
	@make -C minilibx-linux fclean --no-print-directory
	@echo "\033[1;31m [FCLEAN] \033[0m Executable and object files removed."

re: fclean all

.PHONY: all libft mlx clean fclean re