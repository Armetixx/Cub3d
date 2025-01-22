/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:01:44 by kederhet          #+#    #+#             */
/*   Updated: 2023/11/13 14:27:48 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	n;
	unsigned long long	tmp;
	int					neg;
	int					i;

	n = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg *= -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		tmp = n;
		n = n * 10 + str[i++] - '0';
		if ((tmp > n) && neg == 1)
			return (-1);
		else if ((tmp > n) && neg == -1)
			return (0);
	}
	return (n * neg);
}

/*
int	main(void)
{
	char	str[] = "18446744073709551617";

	printf("atoi :    %d\n", atoi(str));
	printf("ft_atoi : %d\n", ft_atoi(str));
	return (0);
}
*/