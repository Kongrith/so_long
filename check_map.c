/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 06:11:17 by khkomasa          #+#    #+#             */
/*   Updated: 2024/12/02 16:08:31 by toon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(t_data *data, char **gridmap, t_point cur, char to_fill)
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
		gridmap[cur.y][cur.x] != to_fill)
		return ;
	gridmap[cur.y][cur.x] = 'F';
	floodfill(data, gridmap, (t_point){cur.x - 1, cur.y}, to_fill);
	floodfill(data, gridmap, (t_point){cur.x + 1, cur.y}, to_fill);
	floodfill(data, gridmap, (t_point){cur.x, cur.y - 1}, to_fill);
	floodfill(data, gridmap, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	check_wall(t_data *data, char **gridmap)
{
	int	i;
	int	j;
	int	chk_enclose;

	i = 0;
	j = -1;
	chk_enclose = 1;
	while (++j < data->col && chk_enclose)
		if (gridmap[i][j] != '1')
			chk_enclose = 0;
	j--;
	while (++i < data->row && chk_enclose)
		if (gridmap[i][j] != '1')
			chk_enclose = 0;
	i--;
	while (--j >= 0 && chk_enclose)
		if (gridmap[i][j] != '1')
			chk_enclose = 0;
	j++;
	while (--i >= 0 && chk_enclose)
		if (gridmap[i][j] != '1')
			chk_enclose = 0;
	if (chk_enclose == 0)
		err_handler(data, "Err: Map don't enclose wall completely!!\n", 0);
}

void	check_valid_path(t_data *data, char **gridmap, int is_found, \
t_point index)
{
	t_point	begin;

	while (index.y < data->row && is_found == 0)
	{
		index.x = 0;
		while (index.x < data->col && is_found == 0)
		{
			if (data->map[index.y][index.x] == 'P')
				is_found = 1;
			else
				index.x++;
		}
		if (is_found != 1)
			index.y++;
	}
	begin.x = index.x;
	begin.y = index.y;
	gridmap[index.y][index.x] = '0';
	floodfill(data, gridmap, begin, '0');
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
	int		is_found;
	char	**gridmap;
	t_point	index;

	index.x = 0;
	index.y = 0;
	is_found = 0;
	check_size(data);
	gridmap = make_gridmap(data->map, data->row, data->col);
	check_wall(data, gridmap);
	check_valid_path(data, gridmap, is_found, index);
	free_double_ptr(gridmap);
}
