/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:31:20 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/02/05 02:26:52 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int 	close_handler(t_data *data)
{
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	free(data->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_data *data)
{
	float	next_x;
	float	next_y;

	next_x = data->player_x;
	next_y = data->player_y;

	if (keysym == XK_Escape)
		close_handler(data);
	if (keysym == LEFT)
		data->player_angle -= TURN_SPEED;
	if (keysym == RIGHT)
		data->player_angle += TURN_SPEED;
	if (keysym == UP)
	{
		data->player_x += cos(data->player_angle) * PLAYER_SPEED;
		data->player_y += sin(data->player_angle) * PLAYER_SPEED;
	}
	if (keysym == DOWN)
	{
		data->player_x -= cos(data->player_angle) * PLAYER_SPEED;
		data->player_y -= sin(data->player_angle) * PLAYER_SPEED;
	}
	return (0);
}
