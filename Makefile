NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = operation.c \
	   parsing.c \
		push_swap.c \
		radix.c \
		main.c \
		stacks.c 
OBJ = $(SRC:.c=.o)
AR = ar rcs

all: $(NAME)

 $(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus