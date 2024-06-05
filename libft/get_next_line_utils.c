/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:49:51 by thfranco          #+#    #+#             */
/*   Updated: 2024/02/25 14:10:52 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

int	ft_strchr_gnl(char *s, int c, int flag)
{
	int	i;

	i = 0;
	if (flag == 1 && !s)
		return (-42);
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2, int position)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return (NULL);
	output = malloc(ft_strlen_gnl(s1) + position + 1);
	if (!output)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			output[i] = s1[i];
			i++;
		}
	}
	while (s2 && s2[j] && j < position)
		output[i++] = s2[j++];
	output[i] = '\0';
	if (s1)
		ft_free(&s1);
	return (output);
}

char	*ft_strndup(char *input, int position)
{
	char	*output;
	int		length;
	int		i;

	i = 0;
	length = position;
	output = malloc(length + 1);
	if (!output)
		return (NULL);
	while (input && input[i] && i < position)
	{
		output[i] = input[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
