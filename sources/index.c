/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:18:46 by thfranco          #+#    #+#             */
/*   Updated: 2024/07/20 14:51:50 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	index_envvar(char *cmd, int i)
{
	while (cmd[i] && !ft_isspace(cmd[i]))
		i++;
	return (i);
}

int	index_single(char *cmd, int i)
{
	i++;
	while (cmd[i] && cmd[i++] != '\'')
		;
	return (i);
}

int	index_double(char *cmd, int i)
{
	i++;
	while (cmd[i] && cmd[i++] != '\"')
		;
	return (i);
}

int	type_index(t_type_cmd type, char *cmd, int i)
{
	if (type == HEREDOC || type == APPEND)
		i += 2;
	else if (type == ENV_VAR)
		i = index_envvar(cmd, i);
	else if (type == S_QUOTE)
		i = index_single(cmd, i);
	else if (type == D_QUOTE)
		i = index_double(cmd, i);
	else if (type == CMD || type == ARG)
	{
		while (cmd[i] != 0 && !(ft_isspace(cmd[i])) && cmd[i] != '<'
			&& cmd[i] != '>' && cmd[i] != '|')
			i++;
	}
	else
		i++;
	return (i);
}
