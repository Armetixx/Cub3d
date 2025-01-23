/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:31:20 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/01/22 15:37:01 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int close_handler(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx_connection, cub3d->mlx_window);
	free(cub3d->mlx_connection);
	exit(EXIT_SUCCESS);
}
int	key_handler(int keysym, t_cub3d *cub3d)
{
	//printf("%d\n", keysym);
	if (keysym == XK_Escape)
		close_handler(cub3d);
	return (0);
}