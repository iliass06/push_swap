# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 22:10:13 by iel-fadi          #+#    #+#              #
#    Updated: 2026/02/17 17:19:52 by iel-fadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra
SRC = push_swap.c push_swap_tools.c push_swap_add_tools.c main.c error_leaks.c
OBJ = push_swap.o push_swap_tools.o push_swap_add_tools.o main.o error_leaks.o
HEADER = push_swap.h
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a 

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME):$(OBJ) $(LIBFT)
	$(CC) $(FLAGS)  $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c 
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_PATH) clean
fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: clean