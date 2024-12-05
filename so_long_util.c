/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 05:44:06 by khkomasa          #+#    #+#             */
/*   Updated: 2024/12/05 01:24:07 by toon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**make_gridmap(char **gridmap, int row, int col)
{
	char	**new;
	int		i;
	int		j;

	new = malloc(sizeof(char *) * row);
	i = 0;
	while (i < row)
	{
		new[i] = malloc(col + 1);
		j = 0;
		while (j < col)
		{
			new[i][j] = gridmap[i][j];
			j++;
		}
		new[i][col] = '\0';
		i++;
	}
	new[row] = "";
	return (new);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	redraw_player(t_data *data, char cmd)
{
	if (cmd == 'U')
		draw_player(data, "textures/ship_up.xpm42", data->y, data->x);
	else if (cmd == 'L')
		draw_player(data, "textures/ship_left.xpm42", data->y, data->x);
	else if (cmd == 'D')
		draw_player(data, "textures/ship_down.xpm42", data->y, data->x);
	else if (cmd == 'R')
		draw_player(data, "textures/ship_right.xpm42", data->y, data->x);
}

void	redraw_background_foregroud(t_data *data, int is_player)
{
	if (is_player == 0)
		mlx_image_to_window(data->mlx, data->img_fg, \
		data->x * WIDTH, data->y * HEIGHT);
	else
		mlx_image_to_window(data->mlx, data->img_p, \
		data->x * WIDTH, data->y * HEIGHT);
}

void	render_frame(t_data *data, char cmd, int is_player)
{
	mlx_image_t	*img;
	uint32_t	x;
	uint32_t	y;

	img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (is_player == 0)
		data->img_fg = img;
	else
		data->img_p = img;
	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			mlx_put_pixel(img, x, y, get_rgba(125, 125, 255, 255));
			y++;
		}
		x++;
	}
	redraw_background_foregroud(data, is_player);
	redraw_player(data, cmd);
}
