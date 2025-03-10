/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:23:02 by kederhet          #+#    #+#             */
/*   Updated: 2025/02/24 13:27:56 by armetix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../utils/utils.h"
# include "../errors/errors.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>

# include <stdio.h> //to remove

int		ft_open_file(char *filename);
char	**ft_create_misc_tab(int fd);
int		ft_check_misc_line(char *line);
int		ft_check_misc_tab(char **tab);
char	**ft_sort_misc_tab(char **tab);
char	*ft_check_empty(int fd);
int		ft_check_map(char **map);
char	**ft_get_map(int fd);
int	    ft_check_map_is_valid(int **map);

#endif