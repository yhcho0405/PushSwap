.PHONY: libft all clean fclean re

NAME_PS = push_swap
NAME_CK = checker

SRCS =	srcs/stack.c \
		srcs/operation_ps.c \
		srcs/operation_r.c \
		srcs/utils.c \
		srcs/utils2.c \
		printf/ft_printf.c \
		printf/print_placeholder.c \
		printf/parse_utils.c

SRCS_PS =	srcs/push_swap.c \
			srcs/solve.c \

SRCS_CK =	srcs/checker.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c

GCC_FLAG = -Wall -Werror -Wextra -g -fsanitize=address
CC = gcc $(GCC_FLAG)

OBJS = $(SRCS:.c=.o)
OBJS_PS = $(SRCS_PS:.c=.o)
OBJS_CK = $(SRCS_CK:.c=.o)

all: $(NAME_PS) $(NAME_CK)
	mkdir -p objs/
	mv srcs/*.o objs/
	mv printf/*.o objs/
	mv gnl/*.o objs/

libft:
	make bonus -C libft/

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME_PS): $(OBJS) $(OBJS_PS)
	$(CC) -o $@ $^ -Llibft -lft -I./

$(NAME_CK): $(OBJS) $(OBJS_CK)
	$(CC) -o $@ $^ -Llibft -lft -I./

clean:
	rm -rf objs/
	rm -rf srcs/*.o
	rm -rf printf/*.o
	rm -rf gnl/*.o

fclean: clean
	rm -f $(NAME_PS) $(NAME_CK)

re: fclean all
