/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:10:26 by kederhet          #+#    #+#             */
/*   Updated: 2025/02/24 13:45:45 by armetix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../includes/cub3d.h"

void	ft_set_player_angle(t_data *data, int i, int j)
{
	if (data->tmp_map[j][i] == 'N')
		data->player_angle = PI;
	if (data->tmp_map[j][i] == 'S')
		data->player_angle = 0;
	if (data->tmp_map[j][i] == 'E')
		data->player_angle = PI / 2;
	if (data->tmp_map[j][i] == 'O')
		data->player_angle = 3 * PI / 2;
	data->tmp_map[j][i] = '0';
}

int	ft_get_playerpos(t_data *data)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (data->tmp_map[j])
	{
		i = 0;
		while (data->tmp_map[j][i])
		{
			if (data->tmp_map[j][i] == 'N' || data->tmp_map[j][i] == 'S' || data->tmp_map[j][i] == 'E' || data->tmp_map[j][i] == 'O') //player_angle = N: pi, S: 0, E: pi/2, O: 3*pi/2
			{
				data->player_x = j;
				data->player_y = i;
				ft_set_player_angle(data, i, j);
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
	ft_free_tab(misc_tab); // tableau avec textures jsp quoi en faire pour l'instant lol
	map = ft_get_map(fd);
	if (!ft_check_map(map))
	{
		ft_free_tab(map);
		return (NULL);
	}
	map = ft_space_in_map(map);
	return (map);
}

int **ft_map_to_int(char **map)
{
	int	**new_map;
	int	i;
	int	j;

	i = 0;
	new_map = ft_calloc(sizeof(int *), tab_size(map) + 1);
	while (map[i])
	{
		j = 0;
		new_map[i] = ft_calloc(sizeof(int), ft_strlen(map[i]) + 1);
		while (map[i][j])
		{
			if (map[i][j] == '\n')
			{
				new_map[i][j++] = -1;
				continue ;
			}
			new_map[i][j] = map[i][j] - 48;
			j++;
		}
		new_map[i][j] = -1;
		i++;
	}
	new_map[i] = ft_calloc(sizeof(int), 1);
	return (new_map);
}
