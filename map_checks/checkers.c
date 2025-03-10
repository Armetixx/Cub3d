/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:09:27 by kederhet          #+#    #+#             */
/*   Updated: 2025/02/19 14:43:32 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_check_misc_line(char *line)
{
	int	i;

	i = 0;
	while (!ft_isspace(line[i]))
		i++;
	if (!line[i] || line[i] == '\n')
		return (ft_error("A line before the map was incorrect.", 0));
	while (ft_isspace(line[i]))
		i++;
	if (!line[i] || line[i] == '\n')
		return (ft_error("A line before the map was incorrect.", 0));
	while (!ft_isspace(line[i]) && line[i] != '\n')
		i++;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] && line[i] != '\n')
		return (ft_error("A line before the map was incorrect.", 0));
	return (1);
}

int	ft_check_misc_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i] && i < 4)
	{
		j = 0;
		if (!ft_check_misc_line(tab[i]))
			return (0);
		while (!ft_isspace(tab[i][j]))
			j++;
		if (j > 2)
			return (ft_error("Wrong identifier for cardinal.", 0));
		i++;
	}
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
	return (1);
}

char	**ft_get_map(int fd)
{
	char	*line;
	char	**map;

	line = ft_check_empty(fd);
	map = malloc(sizeof(char *) * 1);
	map[0] = NULL;
	while (line)
	{
		map = ft_tab_add_line(map, line);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

static int	ft_is_a_valid_map_char(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'O' && str[i] != 32 && str[i] != 10)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_map(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		if (ft_line_empty(map[i]) && !ft_line_empty(map[i + 1]))
			return (ft_error("empty line in map", 0));
		if (!ft_is_a_valid_map_char(map[i]))
			return (ft_error("wrong character in the map", 0));
		i++;
	}
	return (1);
}

