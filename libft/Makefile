NAME = libft.a

SRCS = 	ft_putchar_fd.c ft_putnbr_fd.c ft_strlen.c ft_putstr_fd.c ft_strrchr.c ft_strncmp.c
OBJS = $(SRCS:.c=.o)

CXX = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)
	@echo "built $(NAME) successfully"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CXX) $(CCFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
