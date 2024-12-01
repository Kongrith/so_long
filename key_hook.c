/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 05:33:15 by khkomasa          #+#    #+#             */
/*   Updated: 2024/12/02 06:01:12 by toon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_event(t_data *data, char cmd)
{
	if (data->map[data->y][data->x] == 'C')
	{
		data->map[data->y][data->x] = '0';
		render_frame(data, cmd, 0);
		data->keep += 1;
	}
	if (data->collect == data->keep)
	{
		draw_object(data, "texures/exit.xpm42", data->y_exit, data->x_exit);
		data->endgame = 1;
	}
	if (data->map[data->y][data->x] == 'E' && data->endgame == 1)
		end_game(data);
}

void	moveable(t_data *data, char cmd)
{
	if (cmd == 'U')
	{
		data->y -= 1;
		data->img_p->instances[0].y -= HEIGHT;
	}
	else if (cmd == 'L')
	{
		data->x -= 1;
		data->img_p->instances[0].x -= WIDTH;
	}
	else if (cmd == 'D')
	{
		data->y += 1;
		data->img_p->instances[0].y += HEIGHT;
	}
	else if (cmd == 'R')
	{
		data->x += 1;
		data->img_p->instances[0].x += WIDTH;
	}
	data->moves += 1;
	ft_printf("You moved %d times\n", data->moves);
	check_event(data, cmd);
}

void	check_move(t_data *data, char cmd)
{
	if (cmd == 'U' && data->map[data->y - 1][data->x] != '1')
	{
		render_frame(data, cmd, 1);
		moveable(data, 'U');
	}
	else if (cmd == 'L' && data->map[data->y][data->x - 1] != '1')
	{
		render_frame(data, cmd, 1);
		moveable(data, 'L');
	}
	else if (cmd == 'D' && data->map[data->y + 1][data->x] != '1')
	{
		render_frame(data, cmd, 1);
		moveable(data, 'D');
	}
	else if (cmd == 'R' && data->map[data->y][data->x + 1] != '1')
	{
		render_frame(data, cmd, 1);
		moveable(data, 'R');
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			check_move(data, 'U');
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			check_move(data, 'L');
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			check_move(data, 'D');
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			check_move(data, 'R');
		else if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
			mlx_close_window(data->mlx);
	}
}
