#include "so_long.h"

// WIDTH * col, HEIGHT * row
void move(t_data *data, char cmd)
{
	// ft_printf("can move\n");
	if (cmd == 'U')
		data->img->instances[0].y -= HEIGHT;
	else if (cmd == 'L')
		data->img->instances[0].x -= WIDTH;
	else if (cmd == 'D')
		data->img->instances[0].y += HEIGHT;
	else if (cmd == 'R')
		data->img->instances[0].x += WIDTH;
	data->moves += 1;
}

void check_move(t_data *data, char cmd)
{
	ft_printf("map: %c\n", data->map[data->y][data->x]);
	if (cmd == 'U' && data->map[data->y-1][data->x] != '1')
	{
		data->y -= 1;
		move(data, 'U');
	}
	else if (cmd == 'L' && data->map[data->y][data->x - 1] != '1')
	{
		data->x -= 1;
		move(data, 'L');
	}
	else if (cmd == 'D' && data->map[data->y + 1][data->x] != '1')
	{
		data->y += 1;
		move(data, 'D');
	}
	else if (cmd == 'R' && data->map[data->y][data->x + 1] != '1')
	{
		data->x += 1;
		move(data, 'R');
	}
	ft_printf("x: %d, y: %d\n", data->x, data->y);
}

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data *data;

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
		// if (keydata.key != MLX_KEY_ESCAPE)
		// 	printf("%d\n", data->moves);
		// if (data->map[][] == 'E')
		// 	winner(data);
	}
}
