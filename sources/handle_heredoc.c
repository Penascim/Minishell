/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:30:55 by thfranco          #+#    #+#             */
/*   Updated: 2024/08/06 21:58:45 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	create_temp_file(void)
{
	int	fd;

	fd = open("heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		print_error("heredoc: ", strerror(errno));
		exit(1);
	}
	return (fd);
}

void	display_file_content(void)
{
	int		fd;
	char	buffer[1024];
	ssize_t	bytes_read;

	fd = open("heredoc", O_RDONLY);
	if (fd < 0)
	{
		print_error("heredoc: ", strerror(errno));
		exit(1);
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
		write(1, buffer, bytes_read);
	close(fd);
}

void	heredoc_aux(t_token *data, int fd)
{
	char	*line;

	while (42)
	{
		line = readline("heredoc> ");
		if (!line || !ft_strncmp(line, data->next->value,
				ft_strlen(data->next->value)))
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

void	heredoc(t_token *data)
{
	int	fd;

	fd = create_temp_file();
	while (data && data->next != NULL)
	{
		if (data->token == HEREDOC)
		{
			heredoc_aux(data, fd);
		}
		data = data->next;
	}
	close(fd);
	display_file_content();
}
