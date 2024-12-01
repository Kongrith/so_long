NAME	:= so_long

CXX		:= cc
CFLAGS	:= -Wextra -Wall -Werror

LIBMLX	:= libmlx42.a
LIBFT = libft.a
LIBGNL = libgnl.a
LIBFTPRINTF = libftprintf.a

MLX_DIR = ./MLX42
MLX_PATH = $(MLX_DIR)/include/MLX42
LIBFT_DIR = ./libft
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT)
GNL_DIR = ./gnl
GNL_PATH = $(GNL_DIR)/$(LIBGNL)
PRINTF_DIR = ./printf
PRINTF_PATH = $(PRINTF_DIR)/$(LIBFTPRINTF)

HEADERS	:= -I.-I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -I$(MLX_PATH)
LIBS	:= $(MLX_DIR)/build/$(LIBMLX) $(LIBFT_DIR)/$(LIBFT) $(PRINTF_DIR)/$(LIBFTPRINTF) $(GNL_DIR)/$(LIBGNL) \
	-ldl -lglfw -pthread -lm
SRCS	:= so_long.c so_long_util.c init_map.c check_map.c create_map.c key_hook.c
OBJS	:= ${SRCS:.c=.o}

all: libs $(NAME)
	@echo "built $(NAME) successfully"

libs: | $(MY_DIRNAME)
ifneq "$(wildcard $(MLX_DIR) )" ""
	@echo "Skipping download because directory already exists."
else
	bash -c "git clone https://github.com/codam-coding-college/MLX42.git";
endif
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@make -C $(GNL_DIR)
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

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
