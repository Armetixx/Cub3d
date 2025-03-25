/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:12:03 by armetix           #+#    #+#             */
/*   Updated: 2025/03/25 14:14:26 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

int	tab_print(char **tab) // temporaire
{
	int	i;

	if (!tab)
		return (0);
	i = -1;
	while (tab[++i])
		printf("tab[%d] : %s", i, tab[i]);
	return (i);
}

int	ft_check_map_is_valid(int x, int y, char **map, t_data *data)
{
	if (x >= data->map_y || y >= data->map_x || x < 0 || y < 0)
	{
		return (0);
	}
	if (map[x][y] == '1' || map[x][y] == '2')
		return (1);
	if (map[x][y] == '5')
		return (0);
	map[x][y] = '2';
	if (!ft_check_map_is_valid(x - 1, y, map, data))
		return (0);
	if (!ft_check_map_is_valid(x + 1, y, map, data))
		return (0);
	if (!ft_check_map_is_valid(x, y - 1, map, data))
		return (0);
	if (!ft_check_map_is_valid(x, y + 1, map, data))
		return (0);
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
