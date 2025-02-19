/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:18:04 by kederhet          #+#    #+#             */
/*   Updated: 2025/02/19 13:45:25 by kederhet         ###   ########.fr       */
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
	//mlx_clear_window(data->mlx_connection, data->mlx_window);
	draw_map(data);
	draw_player(data);
	cast_fov(data);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img, 0, 0);
}

void	start_game(t_data *data)
{
	cub3d_init(data);
	map_init(data);
	events_init(data);
}

int	main(int argc, char **argv)
{
	int 	fd;
	t_data	*data;
	if (!ft_check_arg(argc, argv))
		return (1);
	fd = ft_open_file(argv[1]);
	if (!fd)
		return (1);
	data = malloc(sizeof(t_data));
	data->name = "cub3d";
	data->tmp_map = ft_make_map(fd);
	if (ft_get_playerpos(data->tmp_map, &data->player_x, &data->player_y))
	start_game(data);
	mlx_loop(data->mlx_connection);
	return (0);
}
