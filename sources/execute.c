/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:17:51 by thfranco          #+#    #+#             */
/*   Updated: 2024/07/03 19:16:03 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**paths;
	char	*part_path;
	char	**s_cmd;

	paths = ft_split(get_env("PATH", envp), ':');
	s_cmd = ft_split(cmd, ' ');
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, s_cmd[0]);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free_tab(paths);
			return (path);
		}
		else
			free(path);
	}
	ft_free_tab(paths);
	ft_free_tab(s_cmd);
	return (cmd);
}

void	print_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (errno != 0)
		perror("");
	exit(1);
}

void	ft_execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = get_path(cmd[0], envp);
	if (path == NULL)
	{
		ft_putstr_fd(cmd[0], 2);
		print_error("command does not exits.\n");
		ft_free_tab(cmd);
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd(cmd[0], 2);
		print_error("command not found.\n");
		ft_free_tab(cmd);
		free(path);
	}
}
