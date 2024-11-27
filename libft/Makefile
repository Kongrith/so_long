NAME = libft.a
SRCS = 	ft_putchar_fd.c ft_putnbr_fd.c ft_strlen.c ft_putstr_fd.c

OBJS = $(SRCS:.c=.o)
CXX = cc
OPTIONS = -Wall -Werror -Wextra
CCFLAGS = $(OPTIONS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CXX) $(CCFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
