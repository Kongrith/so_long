#include "so_long.h"

void ft_randomize(void *param)
{
	t_data *data;

	data = param;
	for (uint32_t i = 0; i < data->img->width; ++i)
	{
		for (uint32_t y = 0; y < data->img->height; ++y)
		{
			uint32_t color = get_rgba(255, 0, 0, 255);
			mlx_put_pixel(data->img, i, y, color);
		}
	}
}

void clear_collectable(t_data *data)
{
	mlx_image_t *img;
	int x;
	int y;
	// int x_end;
	// int y_end;

	x = data->x * WIDTH;
	// x_end = x + WIDTH;
	y = data->y * HEIGHT;
	// y_end = y + HEIGHT;

	img = mlx_new_image(data->mlx, 64, 64);
	mlx_image_to_window(data->mlx, img, 0, 0);
	// while (x < x_end)
	// {
	// 	y = data->y * HEIGHT;
	// 	while (y < y_end)
	// 	{
	// 		mlx_put_pixel(img, x, y, get_rgba(0, 0, 0, 255));
	// 		y++;
	// 	}
	// 	x++;
	// }
	// ft_printf("out of loop\n");
	// data->img = img;
	mlx_put_pixel(img, x, y, get_rgba(255, 0, 0, 255));
	ft_randomize(data);
}

void check_event(t_data *data)
{
	if (data->map[data->y][data->x] == 'C')
	{
		data->map[data->y][data->x] = '0';
		ft_printf("x: %d, y: %d\n", data->x, data->y);
		clear_collectable(data);
		// mlx_put_pixel(data->img, data->x, data->y, get_rgba(125, 125, 255, 255));
		data->keep += 1;
	}
	// ft_printf("end check_event\n");
	if (data->collect == data->keep)
		ft_printf("keep all\n");

	// ft_printf("----\n");
}

void moveable(t_data *data, char cmd)
{
	if (cmd == 'U')
		data->img->instances[0].y -= HEIGHT;
	else if (cmd == 'L')
		data->img->instances[0].x -= WIDTH;
	else if (cmd == 'D')
		data->img->instances[0].y += HEIGHT;
	else if (cmd == 'R')
		data->img->instances[0].x += WIDTH;
	data->moves += 1;
	check_event(data);
	// printf("back to moveable");
}

void check_move(t_data *data, char cmd)
{
	// ft_printf("map: %c\n", data->map[data->y][data->x]);
	if (cmd == 'U' && data->map[data->y-1][data->x] != '1')
	{
		data->y -= 1;
		moveable(data, 'U');
	}
	else if (cmd == 'L' && data->map[data->y][data->x - 1] != '1')
	{
		data->x -= 1;
		moveable(data, 'L');
	}
	else if (cmd == 'D' && data->map[data->y + 1][data->x] != '1')
	{
		data->y += 1;
		moveable(data, 'D');
	}
	else if (cmd == 'R' && data->map[data->y][data->x + 1] != '1')
	{
		data->x += 1;
		moveable(data, 'R');
	}
	ft_printf("check move\n");
	// ft_printf("x: %d, y: %d\n", data->x, data->y);
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
