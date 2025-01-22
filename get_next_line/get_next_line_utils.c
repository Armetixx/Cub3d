/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:28:26 by kederhet          #+#    #+#             */
/*   Updated: 2023/11/30 17:31:19 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*dest;
	unsigned long	i;

	if (count == 0 || size == 0)
	{
		return (NULL);
	}
	if ((count * size) / count != size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	dest = ptr;
	while (i < (count * size))
	{
		dest[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (s1 && s2)
	{
		res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!res)
			return (NULL);
		i = -1;
		while (s1[++i])
		{
			res[i] = s1[i];
		}
		j = 0;
		while (s2[j])
		{
			res[i++] = s2[j];
			j++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
