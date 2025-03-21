/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:23 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/03/21 17:18:11 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	draw_line(data, (int)ray_x, (int)ray_y);
}

t_ray_hit	cast_ray_textured(t_data *data, float angle)
{
	float		prev_x;
	float		prev_y;
	t_ray_hit	hit;

	hit.ray_x = data->player_x;
	hit.ray_y = data->player_y;
	hit.distance = 0;
	while (!is_wall(data, hit.ray_x, hit.ray_y, 1) && hit.distance < MAX_DIST)
	{
		prev_x = hit.ray_x;
		prev_y = hit.ray_y;
		hit.ray_x += (sin(angle) * RAY_STEP);
		hit.ray_y += (cos(angle) * RAY_STEP);
		hit.distance += RAY_STEP;
	}
	ft_wall_hit_direction(data, &hit, prev_x, prev_y);
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
	t_dda_ray	dda;

	dda.ray_dir_x = sin(angle);
	dda.ray_dir_y = cos(angle);
	dda.map_x = (int)(data->player_x / data->tile_size);
	dda.map_y = (int)(data->player_y / data->tile_size);
	dda.delta_dist_x = fabs(1 / dda.ray_dir_x);
	dda.delta_dist_y = fabs(1 / dda.ray_dir_y);
	ft_init_step_and_dist(data, &dda);
	dda.side = ft_dda_side(data, &dda);
	dda.wall_dist = (dda.side_dist_y - dda.delta_dist_y);
	if (dda.side == 0)
		dda.wall_dist = (dda.side_dist_x - dda.delta_dist_x);
	dda.wall_x = data->player_x
		/ data->tile_size + dda.wall_dist * dda.ray_dir_x;
	if (dda.side == 0)
		dda.wall_x = data->player_y
			/ data->tile_size + dda.wall_dist * dda.ray_dir_y;
	dda.wall_x -= floor(dda.wall_x);
	hit.direction = ft_set_wall_direction(dda);
	hit.distance = dda.wall_dist * data->tile_size;
	hit.wall_x = dda.wall_x;
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
		draw_textured_vertical(data, WIDTH - i - 1, wall_height, &hit);
		i++;
	}
}
