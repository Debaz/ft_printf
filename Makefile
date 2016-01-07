NAME = printf_tests
SRCS = main.c ft_printf.c ft_strlen.c ft_strndup.c
OBJS = main.o ft_printf.o ft_strlen.o ft_strndup.o

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) -Wall -Werror -Wextra $(OBJS)

$(OBJS): $(SRCS)
	gcc -c -Wall -Werror -Wextra $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

