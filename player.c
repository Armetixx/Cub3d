/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:23 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/02/05 02:28:09 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
/*
void	draw_player(t_data *data)
{
	mlx_pixel_put(data->mlx_connection, data->mlx_window, data->player_x, data->player_y, BLUE);
}
*/

void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int	sx = (x1 < x2) ? 1 : -1;
	int	sy = (y1 < y2) ? 1 : -1;
	int	err = dx - dy;
	int e2;

	while (x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(data->mlx_connection, data->mlx_window, x1, y1, color);
		e2 = 2 * err;
		if (e2 > -dy) { err -= dy; x1 += sx; }
		if (e2 < dx) { err += dx; y1 += sy; }
	}
}

void	cast_ray(t_data *data, float angle)
{
	float	ray_x;
	float	ray_y;

	ray_x = data->player_x;
	ray_y = data->player_y;
	while (!is_wall(data, ray_x, ray_y))
	{
		ray_x += cos(angle) * RAY_STEP;
		ray_y += sin(angle) * RAY_STEP;
	}
	draw_line(data, (int)data->center_x, (int)data->center_y, (int)ray_x, (int)ray_y, RED_COLOR);
}

void	cast_fov(t_data *data)
{
	int	i;
	float	start_angle;
	float	angle_step;

	i = 0;
	start_angle = data->player_angle - (FOV / 2);
	angle_step = FOV / NUM_RAYS;
	while (i < NUM_RAYS)
	{
		cast_ray(data, start_angle + i * angle_step);
		i++;
	}
}

void	draw_player(t_data *data)
{
	int	i;
	int	j;
	int	line_x;
	int	line_y;
	
	data->center_x = data->player_x + data->player_size / 2;
	data->center_y = data->player_y + data->player_size / 2;
	i = 0;
	while (i < data->player_size)
	{
		j = 0;
		while (j < data->player_size)
		{
			mlx_pixel_put(data->mlx_connection, data->mlx_window, data->player_x + i, data->player_y + j, BLUE);
			j++;
		}
		i++;
	}
	line_x = data->center_x + cos(data->player_angle) * LINE_LENGHT;
	line_y = data->center_y + sin(data->player_angle) * LINE_LENGHT;
	draw_line(data, data->center_x, data->center_y, line_x, line_y, BLUE);
}