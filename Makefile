# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 15:15:06 by cgamora           #+#    #+#              #
#    Updated: 2020/07/28 16:36:11 by cgamora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cgamora.filler
SRC = src/*.c
INCLUDES = libft/libft.a
FLAGS = -g -Wall -Wextra -Werror

all:
	@make -C libft/ all
	gcc $(SRC) -o $(NAME) $(INCLUDES) 

clean:
	@make -C libft/ clean

fclean:
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all