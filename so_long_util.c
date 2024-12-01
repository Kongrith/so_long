#include "so_long.h"


int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void err_handler(char *cmd_failure)
{
	write(1, cmd_failure, ft_strlen(cmd_failure));
	exit(EXIT_FAILURE);
}

void redraw_player(t_data *data, char cmd)
{
	if (cmd == 'U')
		draw_object(data, "texures/ship_up.xpm42", data->y, data->x, 1);
	else if (cmd == 'L')
		draw_object(data, "texures/ship_left.xpm42", data->y, data->x, 1);
	else if (cmd == 'D')
		draw_object(data, "texures/ship_down.xpm42", data->y, data->x, 1);
	else if (cmd == 'R')
		draw_object(data, "texures/ship_right.xpm42", data->y, data->x, 1);
}

void render_frame(t_data *data, char cmd, int is_player)
{
	mlx_image_t *img;

	img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (is_player == 0)
		data->img_fg = img;
	else
		data->img_p = img;
	for (uint32_t x = 0; x < img->width; x++)
		for (uint32_t y = 0; y < img->height; y++)
			mlx_put_pixel(img, x, y, get_rgba(125, 125, 255, 255));
	if (is_player == 0)
		mlx_image_to_window(data->mlx, data->img_fg, data->x * WIDTH, data->y * HEIGHT);
	else
		mlx_image_to_window(data->mlx, data->img_p, data->x * WIDTH, data->y * HEIGHT);
	redraw_player(data, cmd);
}

// void clear_player(t_data *data, char cmd)
// {
// 	mlx_image_t *img;

// 	img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
// 	data->img_p = img;
// 	for (uint32_t x = 0; x < img->width; x++)
// 		for (uint32_t y = 0; y < img->height; y++)
// 			mlx_put_pixel(img, x, y, get_rgba(125, 125, 255, 255));
// 	mlx_image_to_window(data->mlx, data->img_p, data->x * WIDTH, data->y * HEIGHT);
// 	redraw_player(data, cmd);
// }
