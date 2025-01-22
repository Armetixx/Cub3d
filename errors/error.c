/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:19:44 by kederhet          #+#    #+#             */
/*   Updated: 2025/01/22 11:59:54 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../str_utils/str_utils.h"

int	ft_error(char *str, int err)
{
	ft_putstr("Error : ");
	ft_putstr(str);
	ft_putchar('\n');
	return (err);
}

int	ft_check_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		return (ft_error("No argument found.", 0));
	if (argc > 2)
		return (ft_error("Multiple arguments is not allowed !", 0));
	while (argv[1][i])
		i++;
	if (argv[1][--i] != 'b')
		return (ft_error("File name incorrect.", 0));
	if (argv[1][--i] != 'u')
		return (ft_error("File name incorrect.", 0));
	if (argv[1][--i] != 'c')
		return (ft_error("File name incorrect.", 0));
	if (argv[1][--i] != '.')
		return (ft_error("File name incorrect.", 0));
	return (1);
}
