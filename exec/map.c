/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:49:40 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/03/20 14:42:11 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_wall(t_data *data, float x, float y, int is_for_ray)
{
	int	tile_x;
	int	tile_y;
	int	tile_x2;
	int	tile_y2;

	tile_x = (int)((x - 5) / data->tile_size);
	tile_y = (int)((y - 5) / data->tile_size);
	// Si on est hors des limites de la map
	if (tile_x < 0 || tile_x >= data->map_x
		|| tile_y < 0 || tile_y >= data->map_y)
		return (1);
	// Si on vérifie pour les rayons, on ne fait que checker le point exact
	if (is_for_ray)
		return (data->map[(int)(y / data->tile_size)][(int)(x / data->tile_size)] == 1);

	// Sinon, on vérifie les 4 coins du joueur pour éviter qu’il bloque trop tôt
	tile_x2 = (int)((x + data->player_size) / data->tile_size);
	tile_y2 = (int)((y + data->player_size) / data->tile_size);

	return (data->map[tile_y][tile_x] == 1
			|| data->map[tile_y2][tile_x] == 1 ||
			data->map[tile_y][tile_x2] == 1
			|| data->map[tile_y2][tile_x2] == 1);
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
				draw_square(data, y * data->tile_size,
					i * data->tile_size, WHITE);
			y++;
		}
		i++;
	}
}

void	map_init(t_data	*data)
{
	data->map_bool = OFF;
	data->player_angle = 0;
	data->player_size = data->tile_size / 5;
}
