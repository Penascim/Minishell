/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:29:36 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/04 11:29:37 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (find[i] == '\0' || find == NULL)
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (find[j] == str[i + j] && i + j < n)
		{
			if (find[j + 1] == '\0')
			{
				return ((char *)str + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int main()
{
    const char  *big = "AEFBDEFABCDEF";
    const char  *little = "EFA";
    size_t  len = 8;
    char    *t;

    t = ft_strnstr(big, little, len);
    printf("Resutl: %s\n", t);
    return 0;
}*/
