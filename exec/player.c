/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:23 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/03/20 13:08:35 by kederhet         ###   ########.fr       */
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
		//printf("castRay\n");
		ray_y += cos(angle) * RAY_STEP;
		ray_x += sin(angle) * RAY_STEP;
	}
	printf("end\n");
	draw_line(data, (int)data->center_x, (int)data->center_y,
		(int)ray_x, (int)ray_y, RED_COLOR);
}

t_ray_hit	cast_ray_textured(t_data *data, float angle)
{
	float		prev_x;
	float		prev_y;
	float		ray_x;
	float		ray_y;
	t_ray_hit	hit;

	ray_x = data->player_x;
	ray_y = data->player_y;
	hit.distance = 0;
	while (!is_wall(data, ray_x, ray_y, 1) && hit.distance < MAX_DIST)
	{
		prev_x = ray_x;
		prev_y = ray_y;
		ray_x += (sin(angle) * RAY_STEP);
		ray_y += (cos(angle) * RAY_STEP);
		hit.distance += RAY_STEP;
	}
	// Determine which wall face was hit
	if (fabs(ray_y - prev_y) > fabs(ray_x - prev_x))
	{
		// Horizontal wall (North/South)
		if ((ray_y - prev_y) > 0)
			hit.direction = 0; // North
		else
			hit.direction = 1; // South
		hit.wall_x = fmod(ray_x, data->tile_size) / data->tile_size;
	}
	else
	{
		// Vertical wall (East/West)
		if ((ray_x - prev_x) > 0)
			hit.direction = 3; // West
		else
			hit.direction = 2; // East
		hit.wall_x = fmod(ray_y, data->tile_size) / data->tile_size;
	}
	return (hit);
}

void	cast_fov(t_data *data)
{
	int		i;
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

t_ray_hit	cast_ray_dda(t_data *data, float angle)
{
	t_ray_hit	hit;
	float		ray_dir_x;
	float		ray_dir_y;
	int			map_x;
	int			map_y;
	float		side_dist_x;
	float		side_dist_y;
	float delta_dist_x;
    float delta_dist_y;
	int			step_x;
	int			step_y;
	int 		hit_wall;
	int 		side;
	float		wall_dist;
	float 		wall_x;

	ray_dir_x = sin(angle);
	ray_dir_y = cos(angle);
	map_x = (int)(data->player_x / data->tile_size);
	map_y = (int)(data->player_y / data->tile_size);
	delta_dist_x = fabs(1 / ray_dir_x);
	delta_dist_y = fabs(1 / ray_dir_y);
	if (ray_dir_x == 0)
		delta_dist_x = 1e30;
	if (ray_dir_y == 0)
		delta_dist_y = 1e30;
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (data->player_x / data->tile_size - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - data->player_x
				/ data->tile_size) * delta_dist_x;
	}
	if (ray_dir_y < 0) 
	{
		step_y = -1;
		side_dist_y = (data->player_y / data->tile_size - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - data->player_y
				/ data->tile_size) * delta_dist_y;
	}
	hit_wall = 0;
	while (!hit_wall)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		if (map_x < 0 || map_y < 0
			|| map_x >= data->map_x || map_y >= data->map_y)
			break ;
		if (data->map[map_y][map_x] == 1)
			hit_wall = 1;
	}
	if (side == 0)
		wall_dist = (side_dist_x - delta_dist_x);
	else
		wall_dist = (side_dist_y - delta_dist_y);
	if (side == 0)
		wall_x = data->player_y / data->tile_size + wall_dist * ray_dir_y;
	else
		wall_x = data->player_x / data->tile_size + wall_dist * ray_dir_x;
	wall_x -= floor(wall_x);
	if (side == 0)
	{
		if (step_x > 0)
			hit.direction = 2; // East
		else
			hit.direction = 3; // West
	}
	else
	{
		if (step_y > 0)
			hit.direction = 0; // North
		else
			hit.direction = 1; // South
	}
	hit.distance = wall_dist * data->tile_size;
	hit.wall_x = wall_x;
	return (hit);
}

void	render_3d(t_data *data)
{
	int			i;
	float		ray_angle;
	t_ray_hit	hit;
	float		wall_height;

	i = 0;
	while (i < WIDTH)
	{
		ray_angle = data->player_angle - (FOV / 2) + (i / (float)WIDTH) * FOV;
		hit = cast_ray_dda(data, ray_angle);
		hit.distance *= cos(ray_angle - data->player_angle);
		wall_height = (data->tile_size * HEIGHT) / (hit.distance + 0.0001);
		if (wall_height > HEIGHT)
			wall_height = HEIGHT;
		draw_textured_vertical(data, i, ((HEIGHT / 2)
				- (wall_height / 2)), ((HEIGHT / 2) + (wall_height / 2)), &hit);
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
			put_pixel_to_image(data, data->player_x + i,
				data->player_y + j, BLUE);
			j++;
		}
		i++;
	}
}

void draw_cursor(t_data *data, int size, int color)
{
	int	center_x;
	int	center_y;
	int	i;

	i = -size;
	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
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
