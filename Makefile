# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artperez <artperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 09:42:21 by artperez          #+#    #+#              #
#    Updated: 2025/02/03 10:24:12 by artperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_PATH = libft/libft.a
MLX_PATH = minilibx-linux/libmlx.a
FC = src/so_long.c \
     src/mlx.c \
     src/check_map.c \
     src/check_map2.c \
     src/clean.c \
     src/movement.c \
     src/utils.c \
     src/taking_map.c \
     src/put_image.c

FO = $(FC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH):
	make -sC libft/

$(MLX_PATH):
	make -sC minilibx-linux/

$(NAME): $(FO) $(LIBFT_PATH) $(MLX_PATH)
	echo "Compiling so_long"
	$(CC) $(CFLAGS) $(FO) $(LIBFT_PATH) $(MLX_PATH) -lXext -lX11 -o $(NAME)

clean:
	rm -f $(FO)
	make clean -sC libft/
	make clean -sC minilibx-linux/

fclean: clean
	rm -rf $(NAME)
	make fclean -sC libft/

re: fclean all

.PHONY: all clean fclean re