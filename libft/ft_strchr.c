/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:28:07 by thfranco          #+#    #+#             */
/*   Updated: 2024/02/18 20:38:05 by thafranco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;
	int		i;

	i = 0;
	src = (char *)s;
	while (src[i] != c)
	{
		if (src[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)src + i);
}
/*int	main(void) 
{
	const char	*str = "bonjour";
	int	characterToFind = 's';

	char *result = ft_strchr(str, characterToFind);

	if (result != NULL)
	{
		printf("O caractere '%c\n'", characterToFind);
		printf("foi encontrado na posição: %ld\n", result - str);
  	}
	else
	{
	 	printf("O caractere '%c' não foi encontrado.\n", characterToFind);
	}
	return 0;
}*/
