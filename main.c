/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:18:04 by kederhet          #+#    #+#             */
/*   Updated: 2025/01/28 12:32:54 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors/errors.h"
#include "map_checks/map.h"
#include "includes/cub3d.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	int 	fd;
	t_data	data;
	if (!ft_check_arg(argc, argv))
		return (1);
	fd = ft_open_file(argv[1]);
	if (!fd)
		return (1);
	if (!ft_check_cardinal(fd))
		return (1);	
	data.name = "cub3d";
	cub3d_init(&data);
	mlx_loop(data.mlx_connection);
	return (0);
}
