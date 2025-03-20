/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:37:38 by kederhet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/20 15:34:40 by kederhet         ###   ########.fr       */
=======
/*   Updated: 2025/03/20 14:41:10 by gcools           ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	tab_size(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_tab_add_line(char	**tab, char *line)
{
	int		i;
	int		size;
	char	**tmp;

	if (!tab || !line)
		return (0);
	size = tab_size(tab);
	tmp = malloc(sizeof(char *) * (size + 2));
	i = 0;
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp[i] = ft_strdup(line);
	if (!tmp[i++])
		return (NULL);
	tmp[i] = NULL;
	ft_free_tab(tab);
	return (tmp);
}

char	**ft_space_in_map(char **map)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = malloc(sizeof(char *) * (tab_size(map) + 1));
	while (map[i])
	{
		new_map[i] = ft_replace_space_line(map[i], ' ', '5', map);
		i++;
	}
	new_map[i] = NULL;
	ft_free_tab(map);
	return (new_map);
}

int	ft_longest_str_in_tab(char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (count < (int)ft_strlen(tab[i]))
			count = ft_strlen(tab[i]);
		i++;
	}
	return (count);
}

int	tab_print(char **tab) // temporaire
{
	int	i;

	if (!tab)
		return (0);
	i = -1;
	while (tab[++i])
		printf("tab[%d] : %s", i, tab[i]);
	return (i);
}

// int	tab_print_int(int **tab) // temporaire
// {
// 	int	i;
// 	int	j;

// 	if (!tab)
// 		return (0);
// 	i = -1;
// 	while (tab[++i])
// 	{
// 		j = 0;
// 		printf("tab[%d] :", i);
// 		while (tab[i][j] != -1)
// 		{
// 			printf("%d", tab[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 	}
// 	return (i);
// }
