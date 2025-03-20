/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:26:36 by kederhet          #+#    #+#             */
/*   Updated: 2025/03/20 17:34:33 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buf_to_data(char *buf, char *data)
{
	char	*tmp;

	tmp = ft_strjoin(data, buf);
	ft_free(data);
	data = NULL;
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*ft_read_to_data(int fd, char *data, char *buf)
{
	int		check;

	check = 1;
	if (data == NULL)
	{
		data = ft_calloc(1, sizeof(char));
		if (!data)
			return (NULL);
	}
	while (check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
			return (NULL);
		buf[check] = '\0';
		data = ft_buf_to_data(buf, data);
		if (!data)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			check = 0;
	}
	return (data);
}

char	*ft_data_to_line(char *line, char *data)
{
	int	i;

	i = 0;
	if (!data[i])
		return (NULL);
	while (data[i] != '\n' && data[i])
		i++;
	if (data[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (data[i] != '\n' && data[i])
	{
		line[i] = data[i];
		i++;
	}
	if (data[i] && data[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_clear_data(char *data)
{
	free(data);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		data = ft_free(data);
		return (NULL);
	}
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
	{
		data = ft_free(data);
		return (NULL);
	}
	line = NULL;
	data = ft_read_to_data(fd, data, buf);
	buf = ft_free(buf);
	if (!data)
		return (NULL);
	line = ft_data_to_line(line, data);
	data = ft_clear_data(data);
	return (line);
}

/*
int	main(void)
{
	int		fd;
	int		i;
	char	*test;

	i = 100000;
	fd = open("text.txt", O_RDONLY);
	while (i > 0)
	{
		test = get_next_line(fd);
		printf("%s", test);
		free (test);
		i--;
	}
	close(fd);
//	system("leaks a.out");
	return (0);
}
*/