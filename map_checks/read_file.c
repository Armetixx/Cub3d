/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:06:49 by kederhet          #+#    #+#             */
/*   Updated: 2025/03/21 18:06:28 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

int	ft_open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (ft_error("Can't access file.", 0));
	return (fd);
}

char	*ft_check_empty(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while ((ft_isspace(line[i]) || line[i] == '\n'))
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			if (!line)
				return (NULL);
			i = 0;
		}
	}
	return (line);
}

char	**ft_create_misc_tab(int fd)
{
	char	*line;
	char	**tab;
	int		i;
	int		j;

	j = 0;
	tab = malloc(sizeof(char *) * (6 + 1));
	line = ft_check_empty(fd);
	while (line && j < 6)
	{
		i = 0;
		while (ft_isspace(line[i]))
			i++;
		tab[j] = ft_strdup(line + i);
		free(line);
		j++;
		if (j < 6)
			line = ft_check_empty(fd);
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_sort_misc_tab(char **tab, t_data *data)
{
	int		i;
	char	**misc_tab;

	i = 0;
	misc_tab = ft_calloc(sizeof(char *), (6 + 1));
	while (tab[i])
	{
		if (!misc_tab[0] && !ft_strncmp(tab[i], "NO", 2))
			misc_tab[0] = ft_strdup(tab[i]);
		if (!misc_tab[1] && !ft_strncmp(tab[i], "SO", 2))
			misc_tab[1] = ft_strdup(tab[i]);
		if (!misc_tab[2] && !ft_strncmp(tab[i], "WE", 2))
			misc_tab[2] = ft_strdup(tab[i]);
		if (!misc_tab[3] && !ft_strncmp(tab[i], "EA", 2))
			misc_tab[3] = ft_strdup(tab[i]);
		if (!misc_tab[4] && !ft_strncmp(tab[i], "F", 1))
			misc_tab[4] = ft_strdup(tab[i]);
		if (!misc_tab[5] && !ft_strncmp(tab[i], "C", 1))
			misc_tab[5] = ft_strdup(tab[i]);
		i++;
	}
	misc_tab[6] = NULL;
	data->floor = ft_strdup(misc_tab[4]);
	data->ceiling = ft_strdup(misc_tab[5]);
	return (misc_tab);
}
