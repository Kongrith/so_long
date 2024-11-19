NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ./MLX42
CXX 	:= cc
# HEADERS	:= -I ./include -I $(LIBMLX)/include/MLX42
HEADERS	:= -I $(LIBMLX)/include/MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS	:= $(shell find ./src -iname "*.c")
SRCS	:= main.c
OBJS	:= ${SRCS:.c=.o}



all: $(NAME)
	@echo "built $(NAME) successfully"

%.o: %.c
	@$(CXX) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
