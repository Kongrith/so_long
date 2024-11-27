#ifndef SO_LONG_H
# define SO_LONG_H


# include "MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFER_SIZE 42
# define WIDTH 256
# define HEIGHT 256
#include <stdio.h>

typedef struct s_data
{
	void *mlx;
	mlx_image_t *img;
	// void *mlx_win;
	// void *img_1;
	// void *img_0;
	// void *img_p;
	// void *img_e;
	// void *img_c;
	// void *img_y;
	// int width;
	// int height;
	char **map;
	// int col_len;
	// int row_len;
	// int p_col;
	// int p_row;
	// int lap;
	// char *player;
	// char key;
	// int c;
	int row;
	int col;
	// int exit;
	char moves;
} t_data;

// Mandatory Function
char *get_next_line(int fd);
char *read_from_file(int fd, char *data);
void data_copy(char *data, char *extracted_line);
char *elaborate_data(char *data);
char *stash_data(char *data, int i, int j);

// Utility Function
size_t ft_strlen(const char *s);
char *ft_strchr(char *s, int c);
char *ft_strdup(const char *s1);
char *join_string(char *ptr, char *s1, char *s2);
char *ft_strjoin(char *s1, char *s2);

void err_handler(char *cmd_failure);
int get_rgba(int r, int g, int b, int a);
void draw_background(t_data *data);
void draw_player(t_data *data);
void check_map(t_data *data, char argv[]);
#endif
