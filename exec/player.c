/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:23 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/02/14 17:01:45 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Fonction pour la map en 2D
void	cast_ray(t_data *data, float angle)
{
	float	ray_x;
	float	ray_y;

	ray_x = data->player_x + data->player_size / 2;
	ray_y = data->player_y + data->player_size / 2;
	while (!is_wall(data, ray_x, ray_y, 1))
	{
		ray_y += cos(angle) * RAY_STEP;
		ray_x += sin(angle) * RAY_STEP;
	}
	draw_line(data, (int)data->center_x, (int)data->center_y, (int)ray_x, (int)ray_y, RED_COLOR);
}

float	cast_ray_3d(t_data *data, float angle)
{
	float	ray_x;
	float	ray_y;
	float	distance;
	
	ray_x = data->player_x;
	ray_y = data->player_y;	
	distance = 0;
	while (!is_wall(data, ray_x, ray_y, 1) && distance < MAX_DIST)
	{
		ray_y += cos(angle) * RAY_STEP;
		ray_x += sin(angle) * RAY_STEP;
		distance += RAY_STEP;
	}
	return (distance);
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

void	render_3d(t_data *data)
{
	int		i;
	float	ray_angle;
	float	distance_to_wall;
	float	wall_height;
	int		wall_top;
	int		wall_bottom;

	i = 0;
	while (i < WIDTH)
	{
		ray_angle = data->player_angle - (FOV / 2) + (i / (float)WIDTH) * FOV;
		distance_to_wall = cast_ray_3d(data, ray_angle);
		distance_to_wall *= cos(data->player_angle - ray_angle);
		wall_height = (data->tile_size * HEIGHT) / (distance_to_wall + 0.0001);
		if (wall_height > HEIGHT)
			wall_height = HEIGHT;
		wall_top = (HEIGHT / 2) - (wall_height / 2);
		wall_bottom = (HEIGHT / 2) + (wall_height / 2);
		draw_vertical_line(data, i, wall_top, wall_bottom, WHITE);
		i++; 
	}
}

void	draw_player(t_data *data)
{
	int	i;
	int	j;
	
	data->center_x = data->player_x + data->player_size / 2;
	data->center_y = data->player_y + data->player_size / 2;
	i = 0;
	while (i < data->player_size)
	{
		j = 0;
		while (j < data->player_size)
		{
			put_pixel_to_image(data, data->player_x + i, data->player_y + j, BLUE);
			//mlx_pixel_put(data->mlx_connection, data->mlx_window, data->player_x + i, data->player_y + j, BLUE);
			j++;
		}
		i++;
	}	
}

void draw_cursor(t_data *data, int size, int color)
{
    int center_x = WIDTH / 2;
    int center_y = HEIGHT / 2;
    int i;

    i = -size;
    while (i <= size)
	{
        put_pixel_to_image(data, center_x + i, center_y, color);
		i++;
	}
	i = -size;
    while (i <= size)
	{
        put_pixel_to_image(data, center_x, center_y + i, color);
		i++;
	}
}
