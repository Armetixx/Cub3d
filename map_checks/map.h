/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:23:02 by kederhet          #+#    #+#             */
/*   Updated: 2025/01/22 14:21:56 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../str_utils/str_utils.h"
# include "../errors/errors.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>

# include <stdio.h> //to remove

int	ft_open_file(char *filename);
int	ft_check_cardinal(int fd);

#endif