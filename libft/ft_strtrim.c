/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:32:06 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/04 11:32:07 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
	return (str);
}

/*int	main(int ac, char **av)
{
	(void)ac;
	char *trimmed = ft_strtrim(av[1], av[2]);

    if (trimmed != NULL) {
        printf("String original: \"%s\"\n", av[1]);
        printf("String aparada:  \"%s\"\n", trimmed);

        // Libera a memória alocada para a string "aparada"
        free(trimmed);
    } else 
        printf("Erro na alocação de memória ou entrada nula.\n");
    return (0);
}*/
