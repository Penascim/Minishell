/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:44:47 by thfranco          #+#    #+#             */
/*   Updated: 2024/07/30 12:26:10 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_type_cmd	find_type_cont(char *cmd, int i, int first_token)
{
	(void)first_token;
	if (cmd[i] == '\'')
		return (S_QUOTE);
	else if (cmd[i] == '\"')
		return (D_QUOTE);
	else
	{
		//if (first_token)
			return (CMD);
		//else
			//return (ARG);
	}
}

t_type_cmd	find_type(char *cmd, int i, int first_token)
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
	else if (cmd[i] == '$' && ft_isalpha(cmd[i + 1]))
		return (ENV_VAR);
	//else if (!first_token && cmd[i] == '-' && ft_isalpha(cmd[i + 1]))
	//	return (ARG);
	else
	{
		return (find_type_cont(cmd, i, first_token));
	}
}

char	*get_token(char *cmd, int i, int start)
{
	char	*token;
	int		token_length;

	token_length = i - start;
	token = NULL;
	if (token_length > 0)
	{
		token = (char *)calloc((token_length + 1), sizeof(char));
		ft_strncpy(token, cmd + start, token_length);
		token[token_length] = '\0';
	}
	return (token);
}

int	is_first_token(t_type_cmd type)
{
	if (type == PIPE)
		return (1);
	else
		return (0);
}

t_token	*tokenization(char *cmd, t_token *data)
{
	t_type_cmd	type;
	int			i;
	int			start;
	int			first_token;
	char		*value;

	i = 0;
	first_token = 1;
	data = NULL;
	if (!cmd)
		return (0);
	while (cmd[i] != '\0')
	{
		while (ft_isspace(cmd[i]))
			i++;
		start = i;
		type = find_type(cmd, i, first_token);
		i = type_index(type, cmd, i);
		value = get_token(cmd, i, start);
		data = set_token_list(data, value, type);
		first_token = is_first_token(type);
		free(value);
	}
	return (data);
}
