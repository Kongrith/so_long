/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 06:11:17 by khkomasa          #+#    #+#             */
/*   Updated: 2024/12/02 12:30:28 by toon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(t_data *data, char **gridmap, t_point cur)
{
	if (gridmap[cur.y][cur.x] == 'C')
	{
		data->count_c += 1;
		gridmap[cur.y][cur.x] = '0';
	}
	if (gridmap[cur.y][cur.x] == 'E')
	{
		data->count_e += 1;
		gridmap[cur.y][cur.x] = '0';
	}
	if (cur.y < 0 || cur.y >= data->row || cur.x < 0 || cur.x >= data->col || \
		gridmap[cur.y][cur.x] != '0')
		return ;
	gridmap[cur.y][cur.x] = 'F';
	floodfill(data, gridmap, (t_point){cur.x - 1, cur.y});
	floodfill(data, gridmap, (t_point){cur.x + 1, cur.y});
	floodfill(data, gridmap, (t_point){cur.x, cur.y - 1});
	floodfill(data, gridmap, (t_point){cur.x, cur.y + 1});
}

void	check_wall(t_data *data)
{
	(void)data;
}

void	check_valid_path(t_data *data, int is_found, int i, int j)
{
	t_point	begin;
	char	**gridmap;

	while (i < data->row && is_found == 0)
	{
		j = 0;
		while (j < data->col && is_found == 0)
		{
			if (data->map[i][j] == 'P')
				is_found = 1;
			else
				j++;
		}
		if (is_found != 1)
			i++;
	}
	begin.x = j;
	begin.y = i;
	gridmap = make_gridmap(data->map, data->row, data->col);
	gridmap[i][j] = '0';
	floodfill(data, gridmap, begin);
	if (data->count_e != data->exit)
		err_handler(data, "Err: Player can not reach exit !!\n", 0);
	if (data->count_c != data->collect)
		err_handler(data, "Err: Player can not reach all collectables !!\n", 0);
}

void	check_size(t_data *data)
{
	if (data->col == data->row)
		err_handler(data, "Map should be rectangle !!\n", 0);
	if (data->col <= 2 || data->row <= 2)
		err_handler(data, "Map too small !!\n", 0);
}

void	check_map(t_data *data)
{
	int		i;
	int		j;
	int		is_found;

	i = 0;
	j = 0;
	is_found = 0;
	check_size(data);
	check_wall(data);
	check_valid_path(data, is_found, i, j);
}
