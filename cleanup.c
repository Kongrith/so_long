/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toon <toon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 06:36:22 by khkomasa          #+#    #+#             */
/*   Updated: 2024/12/02 15:40:16 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_double_ptr(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr[i]);
	free(ptr);
}

void cleanup(t_data *data)
{
	free_double_ptr(data->map);
	// mlx_destroy_window(data->mlx, data->img_bg);
	// mlx_destroy_window(data->mlx, data->img_fg);
	// mlx_destroy_window(data->mlx, data->img_p);
}

void err_handler(t_data *data, char *cmd_failure, int clean_mlx)
{
	// if (clean_mlx == 1)
	// 	mlx_close_window(data->mlx);
	cleanup(data);
	if (clean_mlx == 1)
		mlx_destroy_display(data->mlx);
	write(1, cmd_failure, ft_strlen(cmd_failure));
	exit(EXIT_FAILURE);
}
