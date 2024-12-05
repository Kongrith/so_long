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

void	free_double_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] && ptr[i][0] != '\0')
	{
		ft_printf("%d %s", i, ptr[i]);
		if (ptr[i] != NULL)
			free(ptr[i]);
		i++;
	}
	free(ptr[i]);
	// ft_printf("%d %s\n", i, ptr[i]);
	free(ptr);
	ptr = NULL;
}

void	cleanup(t_data *data)
{
	if (data->map)
		free_double_ptr(data->map);
	if (data->img_bg)
		mlx_delete_image(data->mlx, data->img_bg);
	if (data->img_fg)
		mlx_delete_image(data->mlx, data->img_fg);
	if (data->img_p)
		mlx_delete_image(data->mlx, data->img_p);
	// if (data->mlx)
	// 	free(data->mlx);
}

void	err_handler(t_data *data, char *cmd_failure, int clean_mlx)
{
	if (clean_mlx == 1)
		mlx_close_window(data->mlx);
	cleanup(data);
	if (clean_mlx == 1)
		mlx_terminate(data->mlx);
	write(1, cmd_failure, ft_strlen(cmd_failure));
	exit(EXIT_FAILURE);
}
