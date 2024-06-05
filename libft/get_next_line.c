/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:49:21 by thfranco          #+#    #+#             */
/*   Updated: 2024/02/25 17:29:48 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_gnl(size_t n_elements, size_t size)
{
	char			*allocated_memory;
	size_t			total;
	unsigned int	i;

	i = 0;
	total = n_elements * size;
	allocated_memory = (char *)malloc(total);
	if (!allocated_memory)
		return (0);
	while (i < total)
	{
		allocated_memory[i] = 0;
		i++;
	}
	return (allocated_memory);
}

char	*ft_update_next_line(char **next_line, int position)
{
	char	*temp;
	int		length;

	length = ft_strlen_gnl(*next_line) - position;
	temp = ft_strndup(*next_line + position, length);
	ft_free(next_line);
	*next_line = temp;
	return (*next_line);
}

char	*ft_output(char **next_line, int position, int bytes)
{
	char	*line;

	if (((bytes == 0 || bytes == -1) && !*next_line) || position == -42)
	{
		if (*next_line)
			return (*next_line);
		return (NULL);
	}
	line = NULL;
	if (position == -1)
		position = ft_strlen_gnl(*next_line);
	else
		position++;
	line = ft_strndup(*next_line, position);
	if (position == ft_strlen_gnl(*next_line))
		ft_free(next_line);
	else
		*next_line = ft_update_next_line(next_line, position);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*buff;
	int			position;
	int			bytes;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = NULL;
	bytes = 0;
	position = ft_strchr_gnl(next_line, '\n', 0);
	while (position == -1 && position != -42)
	{
		buff = ft_calloc_gnl(BUFFER_SIZE + 1, 1);
		if (buff == NULL)
			return (NULL);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0 || bytes == -1)
			break ;
		next_line = ft_strnjoin(next_line, buff, bytes);
		position = ft_strchr_gnl(next_line, '\n', 1);
		ft_free(&buff);
	}
	ft_free(&buff);
	return (ft_output(&next_line, position, bytes));
}
