NAME = libgnl.a

SRCS = 	get_next_line.c get_next_line_utils.c
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
