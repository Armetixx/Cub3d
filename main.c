/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:18:04 by kederhet          #+#    #+#             */
/*   Updated: 2025/02/05 02:05:29 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	game_loop(t_data *data)
{
	update_game(data);
	return (0);
}

void	update_game(t_data *data)
{
	mlx_clear_window(data->mlx_connection, data->mlx_window);
	draw_map(data);
	draw_player(data);
	cast_fov(data);
}

void	start_game(t_data *data)
{
	cub3d_init(data);
}

int	main(int argc, char **argv)
{
	int 		fd;
	t_data		*data;
	if (!ft_check_arg(argc, argv))
		return (1);
	fd = ft_open_file(argv[1]);
	if (!fd)
		return (1);
	if (!ft_check_cardinal(fd))
		return (1);
	data = malloc(sizeof(t_data));
	data->name = "cub3d";
	start_game(data);
	events_init(data);
	mlx_loop(data->mlx_connection);
	return (0);
}
