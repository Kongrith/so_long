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
#include <stdio.h>




void init_data(t_data *data)
{
	// xpm_t *xpm;
	mlx_image_t *img;

	data->moves = 0;
	data->row = 0;
	data->col = 0;
	data->map = NULL;
	// xpm = NULL;
	img = NULL;

	img = mlx_new_image(data->mlx, 256, 256);
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

void read_map(char argv[], t_data *data)
{
	int i;
	int fd;
	char *line;

	fd = open(argv, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		data->row += 1;
		// printf("%s", line);
		line = get_next_line(fd);
	}
	// printf("row: %d\n", data->row);
	fd = open(argv, O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * (data->row + 1));
	// line = get_next_line(fd);
	// if (line != NULL)
	// 	data->map[0] = line;
	// printf("%d\n", data->row);
	while (i < data->row)
	{
		line = get_next_line(fd);
		data->map[i] = line;
		// printf("[%d]%s", i, line);
		i++;
		// if (line != NULL)
		// {
		// 	data->map[i] = line;
		// 	printf("[%d]%s", i, line);
		// 	i++;
		// }
	}
	data->map[i] = '\0';
	// printf("%s", data->map[0]);
	// printf("%s", data->map[1]);
	// printf("%s", data->map[2]);
	// printf("%s", data->map[3]);
	// printf("%s", data->map[4]);
	// printf("%s", data->map[5]);
}

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data *data;

	data = param;
	if (keydata.action == MLX_PRESS)
	{
		data->moves += 1;
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			data->img->instances[0].y -= 5;
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			data->img->instances[0].x -= 5;
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			data->img->instances[0].y += 5;
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			data->img->instances[0].x += 5;
		else if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
		if (keydata.key != MLX_KEY_ESCAPE)
			printf("%d\n", data->moves);
	}
}
/*

Steps until now :
→ i started by reading the map file using get_next_line();
→ then I stored it in 2d array using add_to_map();
→ then I configured the W, S, A, D and ESC buttons usin key_press();
*/


int main(int argc, char **argv)
{
	void *mlx;
	(void)argv;
	t_data data;
	if (argc != 2)
		err_handler("error\n");
	mlx = mlx_init(WIDTH, HEIGHT, "Cat Me If U Can", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	data.mlx = mlx;
	init_data(&data);
	// read_map(argv[1], &data);

	// printf("%s", data.map[0]);
	// printf("%s", data.map[1]);
	// printf("%s", data.map[2]);
	// printf("%s", data.map[3]);
	// printf("%s", data.map[4]);
	// printf("%s", data.map[5]);

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
