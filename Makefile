NAME = so_long

SRCS = main.c
OBJS = $(SRCS:.c=.o)
CXX = cc
# CCGLAGS = -Wall -Werror -Wextra
CCGLAGS =
# MLXFLAG = -lmlx -lXext -lX11
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# $(NAME): $(OBJ)
# 	$(CXX) $(OBJ) -Lmlx  -lmlx -L/usr/lib -Imlx -lmlx_Linux -lX11 -lXext -o $(NAME)

$(NAME): $(OBJS)
	$(CXX)  -o $(NAME) $(OBJS) $(MLX_FLAGS)

%.o: %.c
	$(CXX)  -I/usr/include -Imlx -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# .PHONY: all clean fclean re
