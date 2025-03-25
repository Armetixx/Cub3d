/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:23:02 by kederhet          #+#    #+#             */
/*   Updated: 2025/03/25 12:04:00 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "utils.h"
# include "errors.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>

# include <stdio.h> //to remove

int		ft_open_file(char *filename);
char	**ft_create_misc_tab(int fd);
int		ft_check_misc_line(char *line);
char	*ft_check_empty(int fd);
int		ft_check_map(char **map);
char	**ft_get_map(int fd);

#endif