/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:34:00 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/04 11:34:05 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	uppercase(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (ft_toupper(c));
	else
		return (ft_tolower(c));
}*/

static size_t	str_len(char const *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

static char	*new_str(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	char	*result;

	if (!s)
		return (NULL);
	str = new_str(str_len(s));
	if (!str)
		return (NULL);
	i = 0;
	result = str;
	while (*s)
		*str++ = f(i++, *s++);
	*str = '\0';
	return (result);
}

/*int	main(void)
{
	const char	*inputString = "Hello, World!";
	char	*result = ft_strmapi(inputString, uppercase);

	if (result)
	{
		printf("Original String: %s\n", inputString);
		printf("Modified String: %s\n", result);
		free(result);
	}
	else
	{
		printf("Erro ao alocar memÃ³ria ou entrada nula.\n");
	}
	return 0;
}*/
