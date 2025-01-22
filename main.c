/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:18:04 by kederhet          #+#    #+#             */
/*   Updated: 2025/01/22 14:22:19 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors/errors.h"
#include "map_checks/map.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	int 	fd;

	if (!ft_check_arg(argc, argv))
		return (1);
	fd = ft_open_file(argv[1]);
	if (!fd)
		return (1);
	if (!ft_check_cardinal(fd))
		return (1);
	return (0);
}
