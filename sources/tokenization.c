/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:44:47 by thfranco          #+#    #+#             */
/*   Updated: 2024/06/26 14:44:00 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_type_cmd	find_type(char *cmd, int i)
{
	if (cmd[i] == '<' && cmd[i + 1] == '<')
		return (HEREDOC);
	else if (cmd[i] == '<')
		return (REDIRECT_IN);
	else if (cmd[i] == '>' && cmd[i + 1] == '>')
		return (APPEND);
	else if (cmd[i] == '>')
		return (REDIRECT_OUT);
	else if (cmd[i] == '|')
		return (PIPE);
	else if (cmd[i] == '-' && ft_isalpha(cmd[i + 1]))
		return (ARG);
	else if (cmd[i] == '$' && ft_isalpha(cmd[i + 1]))
		return (ENV_VAR);
	else
		return (CMD);
}

t_token	*get_token(char *cmd, int i, int start, t_type_cmd type)
{
	t_token	*data;
	char	*token;
	int		token_length;

	token_length = i - start;
	data = NULL;
	token = NULL;
	if (token_length > 0)
	{
		token = (char *)calloc((token_length + 1), sizeof(char));
		ft_strncpy(token, cmd + start, token_length);
		token[token_length] = '\0';
		add_node(&data, type, token);
		free(token);
	}
	print_token_list(data);
	return (data);
}
int  index_env(char *cmd, int i)
{
    if (cmd[i++] == '{')
        while (cmd[i] && cmd[i++] != '}');
    else if (cmd[i++] == '(')
        while (cmd[i] && cmd[i++] != ')');
    else
        while(cmd[i] && !ft_isspace(cmd[i++]));
    return (i);
}

int	type_index(t_type_cmd type, char *cmd, int i)
{
	if (type == HEREDOC || type == APPEND)
		i += 2;
	else if (type == ENV_VAR)
		index_env(cmd, i);
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

void	tokenization(char *cmd)
{
	t_type_cmd	type;
	int			i;
	int			start;
	t_token		*data;

	i = 0;
	if (!cmd)
		return ;
	while (cmd[i] != '\0')
	{
		while (ft_isspace(cmd[i]))
			i++;
		start = i;
		type = find_type(cmd, i);
		i = type_index(type, cmd, i);
		data = get_token(cmd, i, start, type);
	}
	free_list(&data);
}
