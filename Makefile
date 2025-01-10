NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = operations.c \
	   parsing.c \
		push_swap.c \
		radix.c \
		stacks.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

