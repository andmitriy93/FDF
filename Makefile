# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmian <dmian@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 18:45:21 by dmian             #+#    #+#              #
#    Updated: 2020/02/20 19:00:37 by dmian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror
SRC = *.c
NAME = fdf
LIB = libft/libft.a
MLX = minilibx_macos/libmlx.a
FRAMEWORKS	= -framework OpenGL -framework Appkit libft/libft.a
OBJ = $(SRC:.c=.o)

all:
		@make -C libft/ all
		@make -C minilibx_macos/ all
		gcc $(SRC) -o $(NAME) $(FLAGS) $(LIB) $(MLX) $(FRAMEWORKS)

clean:
		@make -C libft/ clean
		@make -C minilibx_macos/ clean

fclean: clean
		/bin/rm -f $(NAME)
		@make -C libft/ fclean

re: fclean all