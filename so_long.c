/*
Steps until now :
→ i started by reading the map file using get_next_line();
→ then I stored it in 2d array using add_to_map();
→ then I configured the W,S,A,D and ESC buttons usin key_press();

https://github.com/iker-gonzalez/so-long/blob/main/main.c
*/

/*
typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t;

typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*        pixels;
	mlx_instance_t* instances;
	int32_t		count;
	bool		enabled;
	void*           context;
}	mlx_image_t;
*/

#include "so_long.h"
#include <stdio.h>

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data *data;

	data = param;
	if (keydata.action == MLX_PRESS)
		data->moves += 1;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		data->img->instances[0].y -= 5;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		data->img->instances[0].x -= 5;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		data->img->instances[0].y += 5;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		data->img->instances[0].x += 5;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.action == MLX_PRESS)
		printf("%d\n", data->moves);
}

int main(int argc, char **argv)
{
	void *mlx;
	mlx_image_t *img;

	t_data data;
	(void)argv;
	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (1);
	}
	mlx = mlx_init(WIDTH, HEIGHT, "Cat Me If U Can", true);
	if (!mlx)
		exit(EXIT_FAILURE);

	/* Do stuff */

	img = mlx_new_image(mlx, 256, 256); // Create and display the image.
	for (uint32_t x = 0; x < img->width; x++)
		for (uint32_t y = 0; y < img->height; y++)
			mlx_put_pixel(img, x, y, rand() % RAND_MAX);

	// mlx_new_image(mlx_t * mlx, uint16_t width, uint16_t height)	Creates a whole new image.
	mlx_image_to_window(mlx, img, 0, 0); // Creates a new instance/copy of an already existing image.

	data.moves = 0;
	data.mlx = mlx;
	data.img = img;
	mlx_key_hook(mlx, &my_keyhook, &data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// str = argv[1];
// ft_initialize(&m, str);
// ft_create_map(&m, str);
// m.col_len -= 1;
// ft_check_ber(str);
// ft_check_errors(&m);
// ft_fill_map(&m);
