/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:30:59 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/04 11:31:01 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		str = malloc(sizeof(char) * 1);
		if (!(str))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
/*int main(void)
{
    char src[] = "substr function Implementation";
 
    int m = 7;
    int n = 12;
 
    char* dest = ft_substr(src, m, n);
 
    printf("%s\n", dest);
 
    return 0;
}*/
