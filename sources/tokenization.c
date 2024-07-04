/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:44:47 by thfranco          #+#    #+#             */
/*   Updated: 2024/07/04 15:22:47 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	else if (!first_token && cmd[i] == '-' && ft_isalpha(cmd[i + 1]))
		return (ARG);
	else
	{
		if (first_token)
			return (CMD);
		else
			return (ARG);
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

t_token *set_token_list(t_token *data, char * value_cmd, int type)
{
	add_node(&data, type, value_cmd);
	//print_token_list(data);
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

int	is_first_token(t_type_cmd type)
{
	if (type == PIPE)
		return (1);
	else
		return (0);
}

t_token	*tokenization(char *cmd)
{
	t_type_cmd	type;
	int			i;
	int			start;
	t_token		*data;
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
	//print_token_list(data);
	return (data);
	//free_list(&data);
}
