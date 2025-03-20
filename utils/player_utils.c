/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:33:27 by kederhet          #+#    #+#             */
/*   Updated: 2025/03/20 15:52:07 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	ft_wall_hit_direction(t_data *data, t_ray_hit *hit,
			float prev_x, float prev_y)
{
	if (fabs(hit->ray_y - prev_y) > fabs(hit->ray_x - prev_x))
	{
		if ((hit->ray_y - prev_y) > 0)
			hit->direction = 0;
		else
			hit->direction = 1;
		hit->wall_x = fmod(hit->ray_x, data->tile_size) / data->tile_size;
	}
	else
	{
		if ((hit->ray_x - prev_x) > 0)
			hit->direction = 3;
		else
			hit->direction = 2;
		hit->wall_x = fmod(hit->ray_y, data->tile_size) / data->tile_size;
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

void	draw_cursor(t_data *data, int size, int color)
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

int	ft_convert_rgb(int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (ft_error("rgb outside range", 0));
	return (r << 16 | g << 8 | b);
}
