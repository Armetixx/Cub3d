/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:31:20 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/03/20 15:10:07 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_handler(t_data *data)
{
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	free(data->mlx_connection);
	exit(EXIT_SUCCESS);
}

void	map_2d_or_3d(t_data *data)
{
	if (data->map_bool == OFF)
		data->map_bool = ON;
	else if (data->map_bool == ON)
		data->map_bool = OFF;
}

void	mouvement_gestion(t_data *data, int keysym)
{
	data->next_x = data->player_x;
	data->next_y = data->player_y;
	if (keysym == 119)
	{
		data->next_y += cos(data->player_angle) * PLAYER_SPEED;
		data->next_x += sin(data->player_angle) * PLAYER_SPEED;
	}
	if (keysym == 115)
	{
		data->next_y -= cos(data->player_angle) * PLAYER_SPEED;
		data->next_x -= sin(data->player_angle) * PLAYER_SPEED;
	}
	if (keysym == 100)
	{
		data->next_y -= sin(data->player_angle) * PLAYER_SPEED;
		data->next_x += cos(data->player_angle) * PLAYER_SPEED;
	}
	if (keysym == 97)
	{
		data->next_y += sin(data->player_angle) * PLAYER_SPEED;
		data->next_x -= cos(data->player_angle) * PLAYER_SPEED;
	}
}

int	key_handler(int keysym, t_data *data)
{
	//printf("%d\n", keysym);
	if (keysym == XK_Escape || keysym == 65307)
		close_handler(data);
	if (keysym == 109)
		map_2d_or_3d(data);
	if (keysym == 65361)
		data->player_angle -= TURN_SPEED;
	if (keysym == 65363)
		data->player_angle += TURN_SPEED;
	mouvement_gestion(data, keysym);
	if (!is_wall(data, data->next_x, data->player_y, 0))
		data->player_x = data->next_x;
	if (!is_wall(data, data->player_x, data->next_y, 0))
		data->player_y = data->next_y;
	return (0);
}
