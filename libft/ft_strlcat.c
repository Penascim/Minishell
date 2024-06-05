/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:27:25 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/04 11:27:31 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d;
	size_t	i;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	d = ft_strlen(dest);
	i = 0;
	if (!size)
		return (ft_strlen(src) + size);
	if (size < d)
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && d + 1 < size)
	{
		dest[d] = src[i];
		i++;
		d++;
	}
	dest[d] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}

/*int	main(void)
{
	char	src[] = "bom dia";
	char	dest[20] = "ola, ";
	
	printf("%ld\n", ft_strlcat(dest, src, sizeof(dest) + sizeof(src)));
	printf("%s\n", dest);
	return (0);
}*/
