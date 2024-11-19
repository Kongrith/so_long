/*
Steps until now :
→ i started by reading the map file using get_next_line();
→ then I stored it in 2d array using add_to_map();
→ then I configured the W,S,A,D and ESC buttons usin key_press();

https://github.com/iker-gonzalez/so-long/blob/main/main.c
*/

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	void *mlx;
	// void *window;

	(void)argv;

	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (1);
	}

	mlx = mlx_init(400, 400, "Title", 1);

	printf("%s\n", argv[1]);
	mlx_loop(mlx);
	return (0);
}

// if (argc != 2)
// {
// 	write(1, "Error\n", 6);
// 	exit(0);
// }
// str = argv[1];
// ft_initialize(&m, str);
// ft_create_map(&m, str);
// m.col_len -= 1;
// ft_check_ber(str);
// ft_check_errors(&m);
// ft_fill_map(&m);
