/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 05:35:25 by khkomasa          #+#    #+#             */
/*   Updated: 2024/12/02 16:07:34 by toon             ###   ########.fr       */
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
		ft_printf("File not found !!\n");
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
		ft_printf("Invalid file extension !!\n");
		exit (EXIT_FAILURE);
	}
}

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
	init_map(&data, argv[1]);
	check_map(&data);
	create_map(&data);
	mlx_key_hook(data.mlx, &my_keyhook, &data);
	mlx_loop(data.mlx);
	cleanup(&data);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
