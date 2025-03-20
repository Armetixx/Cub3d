/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:52:12 by kederhet          #+#    #+#             */
/*   Updated: 2025/03/20 19:21:04 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_free_data_textures(t_data *data)
{
	free(data->north);
	free(data->south);
	free(data->west);
	free(data->east);
	return (0);
}

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
		return (ft_free_data_textures(data));
	fd = open(data->south, O_RDONLY);
	if (fd < 1)
		return (ft_free_data_textures(data));
	fd = open(data->west, O_RDONLY);
	if (fd < 1)
		return (ft_free_data_textures(data));
	fd = open(data->east, O_RDONLY);
	if (fd < 1)
		return (ft_free_data_textures(data));
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

int	ft_free_int_tab(int **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = -1;
	while (tab[++i][0] != 0)
	{
		free(tab[i]);
	}
	free(tab[i]);
	free(tab);
	return (0);
}
