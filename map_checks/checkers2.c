/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:12:03 by armetix           #+#    #+#             */
/*   Updated: 2025/03/21 16:18:48 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

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

int	ft_check_misc_tab_2(t_data *data, char **tab, int i)
{
	int	j;

	while (tab[i])
	{
		j = 0;
		if (!ft_check_misc_line(tab[i]))
			return (0);
		while (!ft_isspace(tab[i][j]))
			j++;
		if (j > 1)
			return (ft_error("Wrong identifier for floor or ceiling.", 0));
		i++;
	}
	if (i != 6)
		return (ft_error("Wrong identifier or duplicated detected.", 0));
	data->rgbceiling = ft_convert_rgb(data->ceiling);
	if (data->rgbceiling == -1)
		return (0);
	data->rgbfloor = ft_convert_rgb(data->floor);
	if (data->rgbfloor == -1)
		return (0);
	return (1);
}
