/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:06:49 by kederhet          #+#    #+#             */
/*   Updated: 2025/01/22 15:47:04 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (ft_error("Can't access file.", 0));
	return (fd);
}

static	char	*ft_check_empty(int fd)
{
	char	*line;
	int		i;
	
	i = 0;
	line = get_next_line(fd);
	while (ft_isspace(line[i]) || line[i] == '\n')
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			i = 0;
		}
	}
	return (line);
}

static	int	ft_check_card_name(char *line, char *card)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp(line + i, card, 2))
		return (0);
	i += 2;
	if (!ft_isspace(line[i]))
		return (0);
	return (1);
}

int	ft_check_cardinal(int fd)
{
	char	*line;
	
	line = ft_check_empty(fd);
	if (!ft_check_card_name(line, "NO"))
		return (ft_error("First cardinal point name is incorrect.", 0));
	free(line);
	line = ft_check_empty(fd);
	if (!ft_check_card_name(line, "SO"))
		return (ft_error("Second cardinal point name is incorrect.", 0));
	free(line);
	line = ft_check_empty(fd);
	if (!ft_check_card_name(line, "WE"))
		return (ft_error("Third cardinal point name is incorrect.", 0));
	free(line);
	line = ft_check_empty(fd);
	if (!ft_check_card_name(line, "EA"))
		return (ft_error("Fourth cardinal point name is incorrect.", 0));
	free(line);
	return (1);
}
