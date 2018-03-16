# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpetras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 07:55:11 by fpetras           #+#    #+#              #
#    Updated: 2018/03/16 12:37:04 by fpetras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c \
	  parsing.c \
	  data_processing.c \
	  validation.c \
	  validation2.c \
	  pathfinding.c \
	  node_route_manager.c \
	  utilities.c \
	  utilities2.c \
	  utilities3.c \
	  free.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
