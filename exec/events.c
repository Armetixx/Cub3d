/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:31:20 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/02/19 14:46:48 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int 	close_handler(t_data *data)
{
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	free(data->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_data *data)
{
	float	next_x = data->player_x;
	float	next_y = data->player_y;

	//printf("%d\n", keysym);
	if (keysym == XK_Escape || keysym == 65307)
		close_handler(data);
	if (keysym == M || keysym == 109)
	{
		if (data->map_bool == OFF)
			data->map_bool = ON;
		else if (data->map_bool == ON)
			data->map_bool = OFF;
	}	
	if (keysym == 49)
	{
		if (data->heart_bool == OFF)
			data->heart_bool = ON;
		else
			data->heart_bool = OFF;
	//	game_loop(data);
	}
	if (keysym == LEFT || keysym == 65361)
		data->player_angle -= TURN_SPEED;
	if (keysym == RIGHT || keysym == 65363)
		data->player_angle += TURN_SPEED;
	if (keysym == UP || keysym == 65362)
	{
		next_y += cos(data->player_angle) * PLAYER_SPEED;
		next_x += sin(data->player_angle) * PLAYER_SPEED;
	}
	if (keysym == DOWN || keysym ==65364)
	{
		next_y -= cos(data->player_angle) * PLAYER_SPEED;
		next_x -= sin(data->player_angle) * PLAYER_SPEED;
	}

	// Vérifie s'il y a un mur avant d'appliquer le mouvement
	if (!is_wall(data, next_x, data->player_y, 0))
		data->player_x = next_x;
	if (!is_wall(data, data->player_x, next_y, 0))
		data->player_y = next_y;
	return (0);
}

