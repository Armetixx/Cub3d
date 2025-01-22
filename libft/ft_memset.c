/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:32:58 by kederhet          #+#    #+#             */
/*   Updated: 2023/10/16 11:45:57 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	char	*dest;

	dest = b;
	while (n > 0)
	{
		*dest = c;
		dest++;
		n--;
	}
	return (b);
}

/*
int main()
{
	char	str[50] = "La SCP facility n'est pas reel.";
	
	printf("\nBefore ft_memset(): %s\n", str);
	ft_memset(str + 16, '/', 17);
	printf("After ft_memset():  %s", str);
	return 0;
}
*/