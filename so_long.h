#ifndef SO_LONG_H
# define SO_LONG_H


# include "MLX42/include/MLX42/MLX42.h"
// # include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define WIDTH 32
# define HEIGHT 32
#include <stdio.h>

typedef struct s_data
{
	void *mlx;
	mlx_image_t *img;
	int x;
	int y;
	char **map;
	int keep;
	int row;
	int col;
	int exit;
	int player;
	int collect;
	int moves;
} t_data;

// Mandatory Function
char *get_next_line(int fd);
char *read_from_file(int fd, char *data);
void data_copy(char *data, char *extracted_line);
char *elaborate_data(char *data);
char *stash_data(char *data, int i, int j);

// Utility Function
// size_t ft_strlen(const char *s);
char *ft_strchr(char *s, int c);
char *ft_strdup(const char *s1);
char *join_string(char *ptr, char *s1, char *s2);
char *ft_strjoin(char *s1, char *s2);

void err_handler(char *cmd_failure);
int get_rgba(int r, int g, int b, int a);
void draw_background(t_data *data);
void draw_player(t_data *data);
void init_map(t_data *data, char argv[]);
void my_keyhook(mlx_key_data_t keydata, void *param);
void create_map(t_data *data);
void check_map(t_data *data);
#endif
