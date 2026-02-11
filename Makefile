NAME = ps.a
CC = cc
FLAGS = -Wall -Werror -Wextra
SRC = push_swap.c
OBJ = push_swap.o
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