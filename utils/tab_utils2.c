/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:52:12 by kederhet          #+#    #+#             */
/*   Updated: 2025/03/25 14:32:47 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// static int	ft_free_data_textures(t_data *data)
// {
// 	free(data->north);
// 	free(data->south);
// 	free(data->west);
// 	free(data->east);
// 	return (0);
// }

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

	data->map = NULL;
	data->north = ft_get_texture_path(tab[0]);
	data->south = ft_get_texture_path(tab[1]);
	data->west = ft_get_texture_path(tab[2]);
	data->east = ft_get_texture_path(tab[3]);
	fd = open(data->north, O_RDONLY);
	if (fd < 1)
		return (0);
	fd = open(data->south, O_RDONLY);
	if (fd < 1)
		return (0);
	fd = open(data->west, O_RDONLY);
	if (fd < 1)
		return (0);
	fd = open(data->east, O_RDONLY);
	if (fd < 1)
		return (0);
	return (1);
}

void	*ft_free_misc_tab(char **tab)
{
	if (tab)
	{
		if (tab[0])
			free(tab[0]);
		if (tab[1])
			free(tab[1]);
		if (tab[2])
			free(tab[2]);
		if (tab[3])
			free(tab[3]);
		if (tab[4])
			free(tab[4]);
		if (tab[5])
			free(tab[5]);
		free(tab);
	}
	return (NULL);
}

int	ft_free_data(t_data *data)
{
	int	i;

	i = -1;
	if (data->map)
	{
		while (data->map[++i][0] != 0)
		{
			free(data->map[i]);
		}
		free(data->map[i]);
		free(data->map);
	}
	ft_free_tab(data->tmp_map);
	free(data->north);
	free(data->south);
	free(data->east);
	free(data->west);
	free(data->floor);
	free(data->ceiling);
	free(data);
	return (0);
}
