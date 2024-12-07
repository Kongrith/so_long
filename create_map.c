/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 05:53:08 by khkomasa          #+#    #+#             */
/*   Updated: 2024/12/05 01:24:11 by toon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background(t_data *data)
{
	mlx_image_t	*img;
	// uint32_t	x;
	// uint32_t	y;

	img = mlx_new_image(data->mlx, WIDTH * data->col, HEIGHT * data->row);
	data->img_bg = img;
	// x = 0;
	// while (x < img->width)
	// {
	// 	y = 0;
	// 	while (y < img->height)
	// 	{
	// 		mlx_put_pixel(img, x, y, get_rgba(125, 125, 255, 255));
	// 		y++;
	// 	}
	// 	x++;
	// }
	mlx_image_to_window(data->mlx, data->img_bg, 0, 0);
}

void	draw_object(t_data *data, char *param, int row, int col)
{
	xpm_t		*xpm;
	mlx_image_t	*img;

	xpm = mlx_load_xpm42(param);
	if (!xpm)
		exit(EXIT_FAILURE);
	img = mlx_texture_to_image(data->mlx, &xpm->texture);
	if (!img)
		exit(EXIT_FAILURE);
	mlx_delete_xpm42(xpm);
	mlx_image_to_window(data->mlx, img, WIDTH * col, HEIGHT * row);
	data->img_fg = img;
}

void	draw_player(t_data *data, char *param, int row, int col)
{
	xpm_t		*xpm;
	mlx_image_t	*img;

	xpm = mlx_load_xpm42(param);
	if (!xpm)
		exit(EXIT_FAILURE);
	img = mlx_texture_to_image(data->mlx, &xpm->texture);
	if (!img)
		exit(EXIT_FAILURE);
	mlx_delete_xpm42(xpm);
	mlx_image_to_window(data->mlx, img, WIDTH * col, HEIGHT * row);
	data->img_p = img;
	data->x = col;
	data->y = row;
}

void	draw_wall_player_collect(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (data->map[i][j] == '1')
				draw_object(data, "./textures/wall.xpm42", i, j);
			if (data->map[i][j] == 'P')
				draw_player(data, "./textures/ship_down.xpm42", i, j);
			if (data->map[i][j] == 'C')
				draw_object(data, "./textures/collectable.xpm42", i, j);
			if (data->map[i][j] == 'E')
			{
				data->x_exit = j;
				data->y_exit = i;
			}
			j++;
		}
		i++;
	}
}

void	create_map(t_data *data)
{
	mlx_t *mlx;

	mlx = mlx_init(WIDTH * data->col, HEIGHT * data->row,
	"Cat Me If U Can", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	data->mlx = mlx;
	draw_background(data);
	// draw_wall_player_collect(data);
}
