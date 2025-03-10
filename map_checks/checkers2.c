/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:12:03 by armetix           #+#    #+#             */
/*   Updated: 2025/02/24 13:42:52 by armetix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_check_map_is_valid(int **map)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x][0] != 0)
	{
		y = -1;
		while (map[x][++y] != -1)
		{
			if (map[x][y] == 0)
			{
				if (y == 0 || x == 0)
					return (ft_error("map is unplayable", 0));
				if (map[x - 1][y] != 1 && map[x - 1][y] != 0)
					return (ft_error("map is unplayable", 0));
				if (map[x + 1][y] != 1 && map[x + 1][y] != 0)
					return (ft_error("map is unplayable", 0));
				if (map[x][y - 1] != 1 && map[x][y - 1] != 0)
					return (ft_error("map is unplayable", 0));
				if (map[x][y + 1] != 1 && map[x][y + 1] != 0)
					return (ft_error("map is unplayable", 0));
			}
		}
	}
	return (1);
}
