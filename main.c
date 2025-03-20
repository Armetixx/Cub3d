/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:18:04 by kederhet          #+#    #+#             */
/*   Updated: 2025/03/18 13:22:04 by kederhet         ###   ########.fr       */
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

void	start_game(t_data *data)
{
	cub3d_init(data);
	map_init(data);
	events_init(data);
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
	data->name = "cub3d";
	data->tmp_map = ft_make_map(fd);
	if (!data->tmp_map)
	{
		free(data);
		return (1);
	}
	if (!ft_get_playerpos(data))
	{
		ft_free_tab(data->tmp_map);
		free(data);
		return (1);
	}
	data->map = ft_map_to_int(data->tmp_map);
	if (!ft_check_map_is_valid(data->map))
	{
		//free tab de int et data
		return (1);
	}
	start_game(data);
	mlx_loop(data->mlx_connection);
	return (0);
}
