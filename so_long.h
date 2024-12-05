/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 06:12:32 by khkomasa          #+#    #+#             */
/*   Updated: 2024/12/05 01:32:58 by toon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define WIDTH 32
# define HEIGHT 32

typedef struct s_data
{
	void		*mlx;
	mlx_image_t	*img_bg;
	mlx_image_t	*img_fg;
	mlx_image_t	*img_p;
	int			x;
	int			y;
	int			x_exit;
	int			y_exit;
	char		**map;
	int			keep;
	int			row;
	int			col;
	int			exit;
	int			player;
	int			collect;
	int			moves;
	int			endgame;
	int			count_c;
	int			count_e;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// So Long
void	init_map(t_data *data, char argv[]);
void	check_map(t_data *data);
void	create_map(t_data *data);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	end_game(t_data *data);
void	err_handler(t_data *data, char *cmd_failure, int clean_mlx);
void	draw_background(t_data *data);
void	draw_object(t_data *data, char *param, int row, int col);
void	draw_player(t_data *data, char *param, int row, int col);
void	render_frame(t_data *data, char cmd, int is_player);
void	cleanup(t_data *data);
int		get_rgba(int r, int g, int b, int a);
char	**make_gridmap(char **gridmap, int row, int col);
void	free_double_ptr(char **ptr);

// 42 Function

char	*ft_strdup(const char *s1);
char	*join_string(char *ptr, char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);

#endif
