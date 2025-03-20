/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:24:52 by kederhet          #+#    #+#             */
/*   Updated: 2025/03/20 15:29:09 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_dda_side(t_data *data, t_dda_ray *dda)
{
	int	hit_wall;
	int	side;

	hit_wall = 0;
	while (!hit_wall)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			side = 1;
		}
		if (dda->map_x < 0 || dda->map_y < 0
			|| dda->map_x >= data->map_x || dda->map_y >= data->map_y)
			break ;
		if (data->map[dda->map_y][dda->map_x] == 1)
			hit_wall = 1;
	}
	return (side);
}

void	ft_init_step_and_dist(t_data *data, t_dda_ray *dda)
{
	if (dda->ray_dir_x == 0)
		dda->delta_dist_x = 1e30;
	if (dda->ray_dir_y == 0)
		dda->delta_dist_y = 1e30;
	dda->step_x = 1;
	dda->side_dist_x = (dda->map_x + 1.0 - data->player_x
			/ data->tile_size) * dda->delta_dist_x;
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (data->player_x
				/ data->tile_size - dda->map_x) * dda->delta_dist_x;
	}
	dda->step_y = 1;
	dda->side_dist_y = (dda->map_y + 1.0 - data->player_y
			/ data->tile_size) * dda->delta_dist_y;
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (data->player_y
				/ data->tile_size - dda->map_y) * dda->delta_dist_y;
	}
}

int	ft_set_wall_direction(t_dda_ray dda)
{
	int	direction;

	if (dda.side == 0)
	{
		if (dda.step_x > 0)
			direction = 2;
		else
			direction = 3;
	}
	else
	{
		if (dda.step_y > 0)
			direction = 0;
		else
			direction = 1;
	}
	return (direction);
}
