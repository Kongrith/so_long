NAME	:= so_long

CXX		:= cc
CFLAGS	:= -Wextra -Wall -Werror

LIBMLX	:= libmlx_Linux.a
LIBFT = libft.a
LIBGNL = libgnl.a
LIBFTPRINTF = libftprintf.a

MLX_DIR = ./minilibx-linux
MLX_PATH = $(MLX_DIR)/include/MLX42
LIBFT_DIR = ./libft
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT)
GNL_DIR = ./gnl
GNL_PATH = $(GNL_DIR)/$(LIBGNL)
PRINTF_DIR = ./printf
PRINTF_PATH = $(PRINTF_DIR)/$(LIBFTPRINTF)

HEADERS	:= -I.-I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -I$(MLX_PATH)
LIBS	:= $(MLX_DIR)/$(LIBMLX) $(LIBFT_DIR)/$(LIBFT) $(PRINTF_DIR)/$(LIBFTPRINTF) $(GNL_DIR)/$(LIBGNL) \
	-ldl -lglfw -pthread -lm -lXext -lX11 -lz
SRCS	:= so_long.c init_map.c cleanup.c
OBJS	:= ${SRCS:.c=.o}

all: libs $(NAME)
	@echo "built $(NAME) successfully"

libs:
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@make -C $(GNL_DIR)
	@make -C $(MLX_DIR)

%.o: %.c
	$(CXX) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(GNL_DIR)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(MLX_DIR)/build/$(LIBMLX)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@make fclean -C $(GNL_DIR)

re: clean all

.PHONY: all, clean, fclean, re, $(MLX_DIR)
