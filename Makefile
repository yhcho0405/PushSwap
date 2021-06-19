.PHONY: libft all clean fclean re

SRCS =	srcs/push_swap.c \
		srcs/stack.c \
		srcs/utils.c \
		srcs/operation_ps.c \
		srcs/operation_r.c \
		printf/ft_printf.c \
		printf/print_placeholder.c \
		printf/parse_utils.c \

NAME = push_swap
GCC_FLAG = #-Wall -Werror -Wextra #-g -fsanitize=address
CC = gcc $(GCC_FLAG)

OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

libft:
	make bonus -C libft/

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJS)
	$(CC) -o $@ $^ -Llibft -lft

clean:
	rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
