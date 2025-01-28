/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:18:33 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/01/28 12:34:02 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	events_init(t_data *data)
{
	mlx_hook(data->mlx_window, KeyPress, KeyPressMask, key_handler, data);
	mlx_hook(data->mlx_window, DestroyNotify, StructureNotifyMask, close_handler, data);
}

void	cub3d_init(t_data*data)
{
	data->mlx_connection = mlx_init();
	if (data->mlx_connection == NULL)
		malloc_error();
	data->mlx_window = mlx_new_window(data->mlx_connection, WIDTH, HEIGHT, data->name);
	if (data->mlx_window == NULL)
	{
		mlx_destroy_window(data->mlx_window, data->mlx_connection);
		free(data->mlx_connection);
		malloc_error();
	}
	events_init(data);
	//data_init(cub3d);
}