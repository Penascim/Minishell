/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:10:46 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/08 21:21:41 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counting_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count + 1);
}

static char	**alloc_mem_split(char const *s, char **r, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			len++;
		if (s[i] == c || s[i + 1] == '\0')
		{
			r[j] = malloc(sizeof(char) * (len + 1));
			if (!r[j])
				return (NULL);
			j++;
			len = 0;
			while (s[i + 1] == c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	r[j] = 0;
	return (r);
}

static void	ft_fillsplit(char const *s, char **r, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			r[j][k] = s[i];
			k++;
		}
		if (s[i] == c || s[i + 1] == '\0')
		{
			r[j][k] = '\0';
			k = 0;
			j++;
			while (s[i + 1] == c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
}

static void	ft_free_mem(char *aux, char c, char **r)
{
	int	i;

	i = 0;
	while (i < counting_words(aux, c))
	{
		free(r[i]);
		i++;
	}
	free(aux);
	free(r);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	char	set[2];
	char	*aux;

	if (!s)
		return (NULL);
	set[0] = c;
	set[1] = '\0';
	aux = ft_strtrim(s, set);
	if (!aux)
		return (NULL);
	r = malloc(sizeof(char *) * (counting_words(aux, c) + 1));
	if (!r)
	{
		free(aux);
		return (NULL);
	}
	if (!alloc_mem_split(aux, r, c))
	{
		ft_free_mem(aux, c, r);
		return (NULL);
	}
	ft_fillsplit(aux, r, c);
	free(aux);
	return (r);
}
