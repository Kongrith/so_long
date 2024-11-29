#include "so_long.h"

// void ft_randomize(void *param)
// {
// 	t_data *data;

// 	data = param;
// 	for (uint32_t i = 0; i < data->img->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < data->img->height; ++y)
// 		{
// 			uint32_t color = get_rgba(255, 0, 0, 255);
// 			mlx_put_pixel(data->img, i, y, color);
// 		}
// 	}
// }

void clear_collectable(t_data *data)
{
	// mlx_image_t *img;
	// int x;
	// int y;
	// int x_end;
	// int y_end;

	// x = data->x * WIDTH;
	// x_end = x + WIDTH;
	// y = data->y * HEIGHT;
	// y_end = y + HEIGHT;

	// img = mlx_new_image(data->mlx, 32, 32);
	// while (x < x_end)
	// {
	// 	y = data->y * HEIGHT;
	// 	while (y < y_end)
	// 	{
	// 		mlx_put_pixel(img, x, y, get_rgba(255, 255, 0, 255));
	// 		y++;
	// 	}
	// 	x++;
	// }
	// mlx_image_to_window(data->mlx, img, data->x * WIDTH, data->y * HEIGHT);

	mlx_image_t *img;

	img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_fg = img;
	for (uint32_t x = 0; x < img->width; x++)
		for (uint32_t y = 0; y < img->height; y++)
			mlx_put_pixel(img, x, y, get_rgba(125, 125, 255, 255));
	mlx_image_to_window(data->mlx, data->img_fg, data->x * WIDTH, data->y * HEIGHT);
	draw_object(data, "texures/ship_down.xpm42", data->y, data->x, 1);
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
	if (data->collect == data->keep)
		draw_object(data, "texures/exit.xpm42", data->y_exit, data->x_exit, 0);
}

void moveable(t_data *data, char cmd)
{
	if (cmd == 'U')
		data->img_p->instances[0].y -= HEIGHT;
	else if (cmd == 'L')
		data->img_p->instances[0].x -= WIDTH;
	else if (cmd == 'D')
		data->img_p->instances[0].y += HEIGHT;
	else if (cmd == 'R')
		data->img_p->instances[0].x += WIDTH;
	data->moves += 1;
	check_event(data);
}

void check_move(t_data *data, char cmd)
{
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
