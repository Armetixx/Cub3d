/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:52:12 by kederhet          #+#    #+#             */
/*   Updated: 2025/03/20 16:35:08 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_get_texture_path(char *str)
{
	int		i;
	int		count;
	char	*final;

	i = 0;
	count = 0;
	if (!ft_isspace(str[i]))
		i += 2;
	while (ft_isspace(str[i]))
		i++;
	while (!ft_isspace(str[i++]) && str[i])
		count++;
	i = 0;
	final = ft_calloc(count + 2, sizeof(char));
	if (!ft_isspace(str[i]))
		i += 2;
	while (ft_isspace(str[i]))
		i++;
	count = 0;
	while (!ft_isspace(str[i]) && str[i] && str[i] != '\n')
		final[count++] = str[i++];
	return (final);
}

int	ft_textures_to_data(t_data *data, char **tab)
{
	int	fd;
	data->north = ft_get_texture_path(tab[0]);
	data->south = ft_get_texture_path(tab[1]);
	data->west = ft_get_texture_path(tab[2]);
	data->east = ft_get_texture_path(tab[3]);
	fd = open(data->north, O_RDONLY);
	if (fd < 1)
		return (ft_error("north texture path not accesible", 0));
	fd = open(data->south, O_RDONLY);
	if (fd < 1)
		return (ft_error("south texture path not accesible", 0));
	fd = open(data->west, O_RDONLY);
	if (fd < 1)
		return (ft_error("west texture path not accesible", 0));
	fd = open(data->east, O_RDONLY);
	if (fd < 1)
		return (ft_error("east texture path not accesible", 0));
	return (1);
}
