CC      = cc
CFLAGS  = -Wall -Werror -Wextra

NAME    = push_swap

SRCS    = arg_to_list.c \
           doing_operations1.c \
           doing_operations2.c \
           doing_operations3.c \
           find_stuff.c \
           ft_ft1.c \
           ft_ft2.c \
           main.c \
           sort_utils1.c \
           sort_utils2.c \
           sort_utils3.c \
           stack_operations.c

OBJS    = $(SRCS:.c=.o)

HEADER  = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re