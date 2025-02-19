/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:18:04 by kederhet          #+#    #+#             */
/*   Updated: 2025/02/19 13:42:20 by guillaumeco      ###   ########.fr       */
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
	char	**misc_tab;
	char	**tmp_tab;
	char	**map;
	if (!ft_check_arg(argc, argv))
		return (1);
	fd = ft_open_file(argv[1]);
	if (!fd)
		return (1);
	tmp_tab = ft_create_misc_tab(fd);
	misc_tab = ft_sort_misc_tab(tmp_tab);
	ft_free_tab(tmp_tab);
	if (!ft_check_misc_tab(misc_tab))
		return (1);
	map = ft_get_map(fd);
	if (!ft_check_map(map))
		return (1);
	map = ft_space_in_map(map);
	tab_print(map);
	data = malloc(sizeof(t_data));
	data->name = "cub3d";
	start_game(data);
	mlx_loop(data->mlx_connection);
	return (0);
}
