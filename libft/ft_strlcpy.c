/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:48:07 by kederhet          #+#    #+#             */
/*   Updated: 2023/10/16 11:53:43 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (dstsize > 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

/*
int	main(void)
{
	char	dest[40] = "";
	char	src[] = "";
	unsigned int	size;

	size = 8;
	printf("%zu\n", ft_strlcpy(dest, src, size));
	printf("%lu", strlcpy(dest, src, size));
	return (0);
}
*/