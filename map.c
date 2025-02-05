/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:49:40 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/02/05 02:10:08 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	is_wall(t_data *data, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / data->tile_size);
	map_y = (int)(y / data->tile_size);
	if (map_x < 0 || map_x >= data->map_x || map_y < 0 || map_y >= data->map_y)
		return (1);
	return (data->map[map_y][map_x] == 1);
}

static void	draw_square(t_data *data, int x, int y, int color)
{
	int i;
	int	j;
	
	i = 0;
	while (i < data->tile_size)
	{
		j = 0;
		while (j < data->tile_size)
		{
			if (i == 0 || j == 0)
				mlx_pixel_put(data->mlx_connection, data->mlx_window, x + j, y + i, BLACK);
			else
				mlx_pixel_put(data->mlx_connection, data->mlx_window, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	while (i < data->map_y)
	{
		y = 0;
		while (y < data->map_x)
		{
			if (data->map[i][y] == 1)
				draw_square(data, y * data->tile_size, i * data->tile_size, WHITE);
			y++;
		}
		i++;
	}
}

void	map_init(t_data	*data)
{
	int	map_y = 10;
	int	map_x = 10;
	int	i;
	int	y;
	
	i = 0;
	int	map[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 2, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	
	};
	data->map_x = map_x;
	data->map_y = map_y;
	if (map_x > map_y)
		data->tile_size = HEIGHT / map_x;
	else
		data->tile_size = HEIGHT / map_y;
	data->player_size = data->tile_size / 5;
	while (i < data->map_y)
	{
		y = 0;
		while (y < data->map_x)
		{
			if (map[i][y] == 2)
			{
				data->player_x = i * data->tile_size + (data->tile_size / 2) - (data->player_size);
				data->player_y = y * data->tile_size + (data->tile_size / 2) - (data->player_size);
			}
			data->map[i][y] = map[i][y];
			y++;
		}
		i++;
	}
	draw_map(data);
}


// Problème : j'initialise les coords de mon player mais celui ci est considéré comme autre que `0` et donc comme un wall