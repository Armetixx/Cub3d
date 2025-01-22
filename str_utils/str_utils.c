/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:21:11 by kederhet          #+#    #+#             */
/*   Updated: 2025/01/22 13:29:41 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_utils.h"

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
