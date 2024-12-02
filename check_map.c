/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 06:11:17 by khkomasa          #+#    #+#             */
/*   Updated: 2024/12/02 08:43:24 by toon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(t_data *data)
{
	(void)data;
}

void	check_valid_path(t_data *data)
{
	(void)data;
}

void	check_size(t_data *data)
{
	if (data->col == data->row)
	// {
	// 	ft_printf("Map should be rectangle !!\n");
	// 	exit (EXIT_FAILURE);
	// }
		err_handler(data, "Map should be rectangle !!\n", 0);
	if (data->col <= 2 || data->row <= 2)
	// {
	// 	ft_printf("Map too small !!\n");
	// 	exit(EXIT_FAILURE);
	// }
		err_handler(data, "Map too small !!\n", 0);
}

void	check_map(t_data *data)
{
	check_size(data);
	check_wall(data);
	check_valid_path(data);
}
