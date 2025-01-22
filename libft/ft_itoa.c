/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:51:01 by kederhet          #+#    #+#             */
/*   Updated: 2025/01/21 15:18:52 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		i;
	long	nb;

	nb = n;
	i = ft_intlen(nb);
	nbr = malloc(ft_intlen(nb) * sizeof(char) + 1);
	if (!nbr)
		return (NULL);
	nbr[i--] = '\0';
	if (nb == 0)
		nbr[i] = '0';
	else if (nb < 0)
	{
		nb *= -1;
		nbr[0] = '-';
	}
	while (nb != 0)
	{
		nbr[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (nbr);
}

/*
int	main(void)
{
	printf("%s\n", ft_itoa(147483648));
	return (0);
}
*/