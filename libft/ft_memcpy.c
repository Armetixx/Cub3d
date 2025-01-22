/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:42:04 by kederhet          #+#    #+#             */
/*   Updated: 2023/10/16 11:42:17 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*memsrc;
	char	*memdest;
	size_t	i;

	i = 0;
	memsrc = (char *)src;
	memdest = dst;
	if (!memsrc && !memdest)
		return (NULL);
	while (n > 0)
	{
		memdest[i] = memsrc[i];
		i++;
		n--;
	}
	return (dst);
}
