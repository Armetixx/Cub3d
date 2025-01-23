/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:18:04 by kederhet          #+#    #+#             */
/*   Updated: 2025/01/23 12:39:46 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors/errors.h"
#include "map_checks/map.h"
#include "includes/cub3d.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	int 	fd;
	t_cub3d	cub3d;

	if (!ft_check_arg(argc, argv))
		return (1);
	fd = ft_open_file(argv[1]);
	if (!fd)
		return (1);
	if (!ft_check_cardinal(fd))
		return (1);
	cub3d.name = "cub3d";
	cub3d_init(&cub3d);
	mlx_loop(cub3d.mlx_connection);
	return (0);
}
