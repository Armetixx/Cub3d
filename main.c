/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:18:04 by kederhet          #+#    #+#             */
/*   Updated: 2025/03/25 14:42:31 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	game_loop(t_data *data)
{
	if (data->map_bool == ON)
		update_game(data);
	else if (data->map_bool == OFF)
		render_frame(data);
	return (0);
}

void	update_game(t_data *data)
{
	clear_image(data, BLACK);
	draw_map(data);
	draw_player(data);
	cast_fov(data);
	mlx_put_image_to_window(data->mlx_connection,
		data->mlx_window, data->img, 0, 0);
}

int	start_game(t_data *data)
{
	if (!cub3d_init(data))
	{
		if (data->north_texture.adrr)
			mlx_destroy_image(data->mlx_connection, data->north_texture.img);
		if (data->south_texture.adrr)
			mlx_destroy_image(data->mlx_connection, data->south_texture.img);
		if (data->east_texture.adrr)
			mlx_destroy_image(data->mlx_connection, data->east_texture.img);
		if (data->west_texture.adrr)
			mlx_destroy_image(data->mlx_connection, data->west_texture.img);
		free(data->mlx_connection);
		return (0);
	}
	map_init(data);
	events_init(data);
	mlx_loop(data->mlx_connection);
	return (1);
}

static	void	init_data(t_data *data)
{
	data->map = NULL;
	data->north = NULL;
	data->south = NULL;
	data->east = NULL;
	data->west = NULL;
	data->north_texture.adrr = NULL;
	data->south_texture.adrr = NULL;
	data->east_texture.adrr = NULL;
	data->west_texture.adrr = NULL;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	*data;

	if (!ft_check_arg(argc, argv))
		return (1);
	fd = ft_open_file(argv[1]);
	if (!fd)
		return (1);
	data = malloc(sizeof(t_data));
	init_data(data);
	data->tmp_map = ft_make_map(fd, data);
	if (!data->tmp_map)
		return (ft_free_data(data));
	if (!ft_get_playerpos(data))
		return (ft_free_data(data));
	if (!ft_check_map_is_valid(data->player_y / data->tile_size, data->player_x
			/ data->tile_size, data->tmp_map, data))
	{
		ft_error("map is unplayable, blame Guillaume", 0);
		return (ft_free_data(data));
	}
	data->map = ft_map_to_int(data->tmp_map);
	if (!start_game(data))
		return (ft_free_data(data));
	return (0);
}
