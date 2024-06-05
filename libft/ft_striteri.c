/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:34:20 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/04 11:34:26 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (s && f)
	{
		while (*s)
			f(i++, s++);
	}
}
/*
void	uppercase(unsigned int index, char *ch)
{
	(void)index;
	*ch = ft_toupper(*ch);
}
int	main(void)
{
	char	str[] = "hello";

	printf("Original String: %s\n", str);
	ft_striteri(str, uppercase);
	printf("Modified String: %s\n", str);
	return (0);
}*/
