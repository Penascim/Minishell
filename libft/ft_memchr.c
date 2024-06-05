/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:29:04 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/04 11:29:06 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/*int	main(int ac, char **av)
{
	(void)ac;
	const char *str = av[1];
	int search = av[2][0];
	size_t n = ft_strlen(str);

	void	*result = ft_memchr(str, search, n);

	printf("%ld\n",(char *)result - str);
	return (0);
}*/
