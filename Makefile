NAME = ps.a
CC = cc
FLAGS = -Wall -Werror -Wextra
SRC = push_swap.c push_swap_tools.c tools_tmp.c main.c
OBJ = push_swap.o push_swap_tools.o tools_tmp.o main.o
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
	rm -f $(NAME)

re: fclean all

.PHONY: clean