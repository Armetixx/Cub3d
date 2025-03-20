/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:21:11 by kederhet          #+#    #+#             */
/*   Updated: 2025/03/20 18:15:38 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int	ft_isspace(char c)
{
	if (c == 9 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

int	ft_line_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\n')
		return (1);
	return (0);
}

char	*ft_replace_space_line(char *str, char to_rep, char add, char **map)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc(sizeof(char) * (ft_longest_str_in_tab(map) + 1));
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != to_rep)
			new_str[i] = str[i];
		else
			new_str[i] = add;
		i++;
	}
	while (i < ft_longest_str_in_tab(map) - 1)
	{
		new_str[i++] = add;
	}
	new_str[i++] = '\n';
	new_str[i] = '\0';
	return (new_str);
}
