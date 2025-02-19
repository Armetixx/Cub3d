/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:10:26 by kederhet          #+#    #+#             */
/*   Updated: 2025/02/19 13:36:49 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../includes/cub3d.h"

int	ft_get_playerpos(char **map, float *player_x, float *player_y)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'E' || map[j][i] == 'O')
			{
				*player_x = j;
				*player_y = i;
				count++;
			}
			i++;
		}
		j++;
	}
	if (count != 1)
		return (ft_error("Wrong number of player in the map", 0));
	return (1);
}

char **ft_make_map(int fd)
{
	char	**misc_tab;
	char	**tmp_tab;
	char	**map;

	tmp_tab = ft_create_misc_tab(fd);
	misc_tab = ft_sort_misc_tab(tmp_tab);
	ft_free_tab(tmp_tab);
	if (!ft_check_misc_tab(misc_tab))
	{
		ft_free_tab(misc_tab);
		return (NULL);
	}
	map = ft_get_map(fd);
	if (!ft_check_map(map))
	{
		ft_free_tab(map);
		return (NULL);
	}
	map = ft_space_in_map(map);
	tab_print(map);
	return (map);
}

int **ft_map_to_int(char ***map)
{
	int	**new_map;
	int	i;
	int	j;

	i = 0;
	new_map = ft_calloc(sizeof(int *), tab_size(*map));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
	}
}