NAME	:= so_long

CXX		:= cc
CFLAGS	:= -Wextra -Wall -Werror

LIBMLX	:= libmlx42.a
LIBFT = libft.a
LIBFTPRINTF = libftprintf.a

MLX_DIR = ./MLX42
MLX_PATH = $(MLX_DIR)/include/MLX42
PRINTF_DIR = ./printf
PRINTF_PATH = $(PRINTF_DIR)/$(LIBFTPRINTF)
LIBFT_DIR = ./libft
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT)

HEADERS	:= -I$(MLX_PATH) -I$(LIBFT_DIR) -I$(PRINTF_DIR)
LIBS	:= $(MLX_DIR)/build/$(LIBMLX) $(LIBFT_DIR)/$(LIBFT) $(PRINTF_DIR)/$(LIBFTPRINTF) -ldl -lglfw -pthread -lm
SRCS	:= so_long.c get_next_line.c get_next_line_utils.c so_long_util.c init_map.c check_map.c \
	create_map.c key_hook.c
OBJS	:= ${SRCS:.c=.o}

all: libs $(NAME)
	@echo "built $(NAME) successfully"

#%.o: %.c so_long.h ./libft/libft.h ./printf/ft_printf.h ./MLX42/include/MLX42/MLX42.h
#	@echo "debug"
#	$(CXX) $(CFLAGS) $(IFLAGS) -c $< -o $@

libs:
	@make -C $(LIBFT_DIR)
#	@cp $(LIBFT_PATH) $(LIBFT)
	@make -C $(PRINTF_DIR)
#	@cp $(PRINTF_PATH) $(LIBFTPRINTF)
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4
#	@cp $(MLX_DIR)/build/$(LIBMLX) $(LIBMLX)

%.o: %.c
	$(CXX) $(CFLAGS) -o $@ -c $< -I. -Iprintf -Ilibft -IMLX42/include/MLX42

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -I. -Iprintf -Ilibft -IMLX42/include/MLX42 -o $(NAME)

# ${NAME}:${OBJS}
# 	${CXX} ${OBJS} ${CFLAGS} ./libft/libft.a ./printf/libftprintf.a ./MLX42/build/libmlx42.a  -L. so_long.h  -L./libft -L./printf    -ldl -lglfw -pthread -lm -o ${NAME}

clean:
	@rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(MLX_DIR)/build/$(LIBMLX)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
