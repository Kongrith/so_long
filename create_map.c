#include "so_long.h"

void create_map(t_data *data)
{
	void *mlx;

	mlx = mlx_init(WIDTH * data->col, HEIGHT * data->row, "Cat Me If U Can", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	data->mlx = mlx;
}
