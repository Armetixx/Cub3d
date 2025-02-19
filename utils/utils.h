/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:43:05 by kederhet          #+#    #+#             */
/*   Updated: 2025/02/19 14:25:30 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTILS_H
# define STR_UTILS_H

# include <unistd.h>
# include <stdio.h> // RETIRER A SUPP
# include "../libft/libft.h"
# include "../includes/cub3d.h"

void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*ft_replace_space_line(char *str, char to_rep, char add, char **map);
int		ft_isspace(char c);
int		ft_line_empty(char *line);
void	ft_free_tab(char **tab);
char	**ft_tab_add_line(char **tab, char *line);
int		tab_print(char **tab);
int		tab_size(char **tab);
char 	**ft_space_in_map(char **map);
int		ft_longest_str_in_tab(char **tab);

char 	**ft_make_map(int fd);

#endif