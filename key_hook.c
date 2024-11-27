#include "so_long.h"

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
