/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 05:25:12 by khkomasa          #+#    #+#             */
/*   Updated: 2024/12/05 01:33:00 by toon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_params(t_data *data)
{
	if (data->exit != 1)
		err_handler(data, "Error\nExit should be only 1 !!\n", 0);
	if (data->player != 1)
		err_handler(data, "Error\nPlayer should be only 1 !!\n", 0);
	if (data->collect == 0)
		err_handler(data, "Error\nCollectable need at least 1 !!\n", 0);
}

void	read_epc(t_data *data)
{
	int		i;
	int		j;
	char	value;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			value = data->map[i][j];
			if (value != 'E' && value != 'P' && value != 'C' && \
			value != '0' && value != '1')
				err_handler(data, "Error\nMap accepts only 01EPC character !!\n", 0);
			if (value == 'E')
				data->exit += 1;
			if (value == 'P')
				data->player += 1;
			if (value == 'C')
				data->collect += 1;
			j++;
		}
		i++;
	}
	check_params(data);
}

void	get_column(t_data *data)
{
	int	i;
	int	prev_col;
	int	current_col;

	i = 0;
	while (i < data->row)
	{
		if (i == 0)
			prev_col = ft_strlen(data->map[i]) - 1;
		else
		{
			current_col = ft_strlen(data->map[i]) - 1;
			if (current_col == prev_col)
				prev_col = current_col;
			else
				err_handler(data, "Error\nEach row should be equal size !!\n", 0);
		}
		i++;
	}
	data->col = current_col;
}

void	read_map(t_data *data, char argv[])
{
	int		i;
	int		fd;
	char	*line;

	line = NULL;
	fd = open(argv, O_RDWR);
	if (fd == -1)
		err_handler(data, "Error\nFile not found !!\n", 0);
	line = get_next_line(fd);
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		data->row += 1;
	}
	data->map = malloc(sizeof(char *) * (data->row + 1));

	close(fd);
	fd = open(argv, O_RDWR);
	i = 0;
	while (i < data->row)
	{
		line = get_next_line(fd);
		data->map[i] = line;
		i++;
	}
	line = get_next_line(fd);
	data->map[i] = line;
	get_column(data);
	close(fd);
}

void	init_map(t_data *data, char argv[])
{
	read_map(data, argv);
	read_epc(data);
}
