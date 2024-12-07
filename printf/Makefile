NAME = libftprintf.a
LIBFTNAME = libft.a

LIBFTDIR = ../libft
LIBFT_PATH = $(LIBFTDIR)/$(LIBFTNAME)

SRCS = ft_printf.c ft_printchar.c ft_printstr.c ft_printptr.c ft_printdec.c ft_printhex.c ft_printuint.c \
		ft_utilities.c
OBJS = $(SRCS:.c=.o)

CXX = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)
	@echo "built $(NAME) successfully"

$(NAME): $(OBJS) Makefile
	@make -C $(LIBFTDIR)
	@cp $(LIBFT_PATH) $(LIBFTNAME)
	@mv $(LIBFTNAME) $(NAME)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h ../libft/libft.h
	$(CXX) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
