/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:56:46 by kederhet          #+#    #+#             */
/*   Updated: 2023/10/19 12:46:56 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	if (str2[i] == '\0')
		return (str1);
	while (str1[i] && i < len)
	{
		if (str1[i] == str2[0])
		{
			j = 0;
			while (str1[i + j] == str2[j] && i + j < len)
			{
				if (str2[j + 1] == '\0')
					return (&str1[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
