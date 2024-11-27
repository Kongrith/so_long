/*
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

./so_long ./maps/exam.ber
*/

#include "so_long.h"
void init_data(t_data *data, char argv[])
{
	// void *mlx;

	data->row = 0;
	data->col = 0;
	data->map = NULL;
	data->moves = 0;
	init_map(data, argv);
	// mlx = mlx_init(WIDTH, HEIGHT, "Cat Me If U Can", true);
	// if (!mlx)
	// 	exit(EXIT_FAILURE);
	// data->mlx = mlx;

	// xpm_t *xpm;
	mlx_image_t *img;


	// xpm = NULL;
	img = NULL;

	img = mlx_new_image(data->mlx, WIDTH * data->col, HEIGHT * data->row);
	data->img = img;
	draw_background(data);
	draw_player(data);

	// Try to load the file
	// xpm = mlx_load_xpm42("texures/test.xpm42");
	// if (!xpm)
	// 	exit(EXIT_FAILURE);

	// Convert texture to a displayable image
	// img = mlx_texture_to_image(data->mlx, &xpm->texture);
		// if (!img)
		// 	exit(EXIT_FAILURE);


	// img = mlx_new_image(data->mlx, 256, 256);
	// for (uint32_t x = 0; x < img->width; x++)
	// 	for (uint32_t y = 0; y < img->height; y++)
	// 		mlx_put_pixel(img, x, y, rand() % RAND_MAX);

	// Display the image
	// if (mlx_image_to_window(data->mlx, img, 0, 0) < 0)
	// 	exit(EXIT_FAILURE);

	// mlx_new_image(mlx_t * mlx, uint16_t width, uint16_t height)	Creates a whole new image.
	// mlx_image_to_window(data->mlx, img, 0, 0); // Creates a new instance/copy of an already existing image.
	// data->img = img;
}


int main(int argc, char **argv)
{
	// void *mlx;
	t_data data;

	if (argc != 2)
		err_handler("error\n");
	init_data(&data ,argv[1]);

	// mlx = mlx_init(WIDTH, HEIGHT, "Cat Me If U Can", true);
	// if (!mlx)
	// 	exit(EXIT_FAILURE);
	// data.mlx = mlx;
	// init_data(&data);
	// read_map(argv[1], &data);
	mlx_key_hook(data.mlx, &my_keyhook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}

// str = argv[1];
// ft_initialize(&m, str);
// ft_create_map(&m, str);
// m.col_len -= 1;
// ft_check_ber(str);
// ft_check_errors(&m);
// ft_fill_map(&m);
