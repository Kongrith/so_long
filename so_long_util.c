#include "so_long.h"

/*
Encodes four individual bytes into an int.
*/
int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void err_handler(char *cmd_failure)
{
	write(1, cmd_failure, ft_strlen(cmd_failure));
	exit(EXIT_FAILURE);
}

void draw_background(t_data *data)
{
	for (uint32_t x = 0; x < data->img->width; x++)
		for (uint32_t y = 0; y < data->img->height; y++)
			mlx_put_pixel(data->img, x, y, get_rgba(125, 125, 255, 255));
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

void draw_player(t_data *data)
{
	xpm_t *xpm;
	mlx_image_t *img;

	xpm = mlx_load_xpm42("texures/test.xpm42");
	if (!xpm)
		exit(EXIT_FAILURE);
	img = mlx_texture_to_image(data->mlx, &xpm->texture);
	if (!img)
		exit(EXIT_FAILURE);

	mlx_image_to_window(data->mlx, img, 0, 0);
	data->img = img;
}

// void chk_input(char argv[])
// {
// 	printf("%s", argv);
// }
