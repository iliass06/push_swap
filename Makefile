# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 22:10:13 by iel-fadi          #+#    #+#              #
#    Updated: 2026/02/15 00:59:27 by iel-fadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ps.a
CC = cc
FLAGS = -Wall -Werror -Wextra
SRC = push_swap.c push_swap_tools.c push_swap_add_tools.c tools_tmp.c main.c error_leaks.c
OBJ = push_swap.o push_swap_tools.o push_swap_add_tools.o tools_tmp.o main.o error_leaks.o
AR = ar rcs
HEADER = push_swap.h

all: $(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(LIBFT)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) push_swap

re: fclean all

.PHONY: clean