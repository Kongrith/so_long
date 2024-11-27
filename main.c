// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 512
#define HEIGHT 512
#define STEP_X 32
#define STEP_Y 32

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

// void ft_hook(void *param)
void ft_hook(void *param)
{
	mlx_t* mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		int i = 0;

		while (i < 1)
		{
			image->instances[0].y -= 2;
			i++;
		}
	}

	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += STEP_Y;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= STEP_X;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += STEP_X;

	// if (keydata.action == MLX_PRESS)
	// {
	// 	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
	// 		image->instances[0].x += STEP_X;
	// 	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
	// 		image->instances[0].x += STEP_X;
	// 	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
	// 		image->instances[0].x += STEP_X;
	// 	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
	// 		image->instances[0].x += STEP_X;
	// 	else if (keydata.key == MLX_KEY_ESCAPE)
	// 		mlx_close_window(mlx);
	// }
}

// -----------------------------------------------------------------------------

int32_t main(void)
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, STEP_X, STEP_Y)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
