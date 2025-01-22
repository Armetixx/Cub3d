/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:23:51 by kederhet          #+#    #+#             */
/*   Updated: 2023/10/17 11:43:28 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	ft_changeletter(unsigned int index, char c)
{
	printf("index : %d, char : %c\n", index, c);
	c = '/';
	return (c);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	if (!s)
		return (NULL);
	i = 0;
	dest = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int main(void)
{
	printf("%s\n", ft_strmapi("Hello-World", &ft_changeletter));
	return (0);
}
*/