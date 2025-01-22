/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:54:36 by kederhet          #+#    #+#             */
/*   Updated: 2023/10/17 11:58:39 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	ft_changeletter(unsigned int index, char *c)
{
	printf("index : %d, char : %c\n", index, *c);
}
*/

char	*ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return (s);
}

/*
int main(void)
{
	printf("%s\n", ft_striteri("HelloWorld", &ft_changeletter));
	return (0);
}
*/