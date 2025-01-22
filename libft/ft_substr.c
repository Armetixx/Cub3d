/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:46:10 by kederhet          #+#    #+#             */
/*   Updated: 2023/10/19 12:05:53 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		start = 0;
		len = 0;
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	dest = malloc (len * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}

/*
int	main(void)
{
	char	*str = "Hello World";

	printf("%s\n", ft_substr(str, 5, 1));
	return (0);
}
*/