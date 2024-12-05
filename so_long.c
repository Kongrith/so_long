/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 05:35:25 by khkomasa          #+#    #+#             */
/*   Updated: 2024/12/05 01:33:31 by toon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_data *data)
{
	ft_printf("Congratulation !! You won the game with %d moves\n", \
data->moves);
	mlx_close_window(data->mlx);
	cleanup(data);
	mlx_terminate(data->mlx);
	exit (EXIT_SUCCESS);
}

void	init_data(t_data *data)
{
	data->img_bg = NULL;
	data->img_fg = NULL;
	data->img_p = NULL;
	data->map = NULL;
	data->keep = 0;
	data->row = 0;
	data->col = 0;
	data->exit = 0;
	data->player = 0;
	data->collect = 0;
	data->moves = 0;
	data->x_exit = 0;
	data->y_exit = 0;
	data->endgame = 0;
	data->count_c = 0;
	data->count_e = 0;
}

void	check_file(char argv[])
{
	char	*ext;
	int		len;
	int		fd;

	fd = open(argv, O_RDWR);
	if (fd == -1)
	{
		ft_printf("Error\nFile not found !!\n");
		exit(EXIT_FAILURE);
	}
	len = 0;
	ext = ft_strrchr(argv, '.');
	if (ft_strlen(ext) >= ft_strlen(".ber"))
		len = ft_strlen(ext);
	else
		len = ft_strlen(".ber");
	if (ft_strncmp(ext, ".ber", len) != 0)
	{
		ft_printf("Error\nInvalid file extension !!\n");
		exit (EXIT_FAILURE);
	}
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/good.ber 2>&1 | tee -a a.txt ;
*/
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("hint: ./so_long <map_file.ber>\n");
		return (EXIT_FAILURE);
	}
	check_file(argv[1]);
	init_data(&data);
	ft_printf("1\n");
	init_map(&data, argv[1]);
	ft_printf("2\n");
	check_map(&data);
	ft_printf("3\n");
	create_map(&data);
	ft_printf("4\n");
	mlx_key_hook(data.mlx, &my_keyhook, &data);
	ft_printf("5\n");
	mlx_loop(data.mlx);
	ft_printf("6\n");
	cleanup(&data);
	ft_printf("7\n");
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
