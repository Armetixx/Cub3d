/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:10:26 by kederhet          #+#    #+#             */
/*   Updated: 2025/02/19 11:14:35 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	*ft_get_playerpos(char	**map)
{
	int	i;
	int	j;
	int	*playerpos;

	playerpos = malloc(2 * sizeof(int));
	if (!playerpos)
		return (0);
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'E' || map[j][i] == 'O')
			{
				playerpos[0] = j;
				playerpos[1] = i;
			}
			i++;
		}
		j++;
	}
	return (playerpos);
}
