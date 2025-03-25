/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:31:20 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/03/25 14:31:16 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_handler(t_data *data)
{
	mlx_destroy_image(data->mlx_connection, data->north_texture.img);
	mlx_destroy_image(data->mlx_connection, data->south_texture.img);
	mlx_destroy_image(data->mlx_connection, data->east_texture.img);
	mlx_destroy_image(data->mlx_connection, data->west_texture.img);
	mlx_destroy_image(data->mlx_connection, data->img);
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	mlx_destroy_display(data->mlx_connection);
	free(data->mlx_connection);
	ft_free_data(data);
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
		data->next_y += sin(data->player_angle) * PLAYER_SPEED;
		data->next_x -= cos(data->player_angle) * PLAYER_SPEED;
	}
	if (keysym == 97)
	{
		data->next_y -= sin(data->player_angle) * PLAYER_SPEED;
		data->next_x += cos(data->player_angle) * PLAYER_SPEED;
	}
}

int	key_handler(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == 65307)
		close_handler(data);
	if (keysym == 109)
		map_2d_or_3d(data);
	if (keysym == 65361)
		data->player_angle += TURN_SPEED;
	if (keysym == 65363)
		data->player_angle -= TURN_SPEED;
	mouvement_gestion(data, keysym);
	if (!is_wall(data, data->next_x, data->player_y, 0))
		data->player_x = data->next_x;
	if (!is_wall(data, data->player_x, data->next_y, 0))
		data->player_y = data->next_y;
	return (0);
}
