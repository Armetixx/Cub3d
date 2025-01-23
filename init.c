/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:18:33 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/01/22 15:35:37 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	events_init(t_cub3d *cub3d)
{
	mlx_hook(cub3d->mlx_window, KeyPress, KeyPressMask, key_handler, cub3d);
	mlx_hook(cub3d->mlx_window, DestroyNotify, StructureNotifyMask, close_handler, cub3d);
}

void	cub3d_init(t_cub3d *cub3d)
{
	cub3d->mlx_connection = mlx_init();
	if (cub3d->mlx_connection == NULL)
		malloc_error();
	cub3d->mlx_window = mlx_new_window(cub3d->mlx_connection, WIDTH, HEIGHT, cub3d->name);
	if (cub3d->mlx_window == NULL)
	{
		mlx_destroy_window(cub3d->mlx_window, cub3d->mlx_connection);
		free(cub3d->mlx_connection);
		malloc_error();
	}
	events_init(cub3d);
	//data_init(cub3d);
}