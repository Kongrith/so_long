NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror

LIBMLX	:= libmlx42.a
LIBPRINTF = libftprintf.a

PRINTF_DIR = ./printf
PRINTF_PATH = $(PRINTF_DIR)/$(LIBPRINTF)
MLX_DIR = ./MLX42
MLX_PATH = $(MLX_DIR)/include/MLX42

HEADERS	:= -I so_long.h $(MLX_PATH) $(PRINTF_PATH)
LIBS	:= $(MLX_DIR)/build/$(LIBMLX) $(PRINTF_DIR)/$(LIBPRINTF) -ldl -lglfw -pthread -lm
SRCS	:= so_long.c get_next_line.c get_next_line_utils.c so_long_util.c init_map.c check_map.c create_map.c \
	key_hook.c
OBJS	:= ${SRCS:.c=.o}

# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

all: $(NAME)

$(NAME): $(OBJS)
#	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
