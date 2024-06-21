/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:15:49 by penascim          #+#    #+#             */
/*   Updated: 2024/06/21 17:00:40 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

/*void	get_token(int token_len, int start)
{
	char	*token;

	token = calloc(token_len, sizeof(char));
	ft_strlcpy(token, )
}*/

void print_token_list(t_token *head) {
    t_token *current = head;

    printf("Lista de Tokens:\n");

    while (current != NULL) {
        printf("Token: %s\n", current->data);
		printf("Tipo: %d\n",current->token);
        current = current->next;
    }
}


static t_token	*last_from_list(t_token *data)
{
	if (!data)
		return (NULL);
	while (data->next)
		data = data->next;
	return (data);
}

static void	add_node(t_token **data, t_type_cmd type, char *value)
{
	t_token	*new_node;
	t_token	*last_node;

	if (!data)
		return ;
	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return ;
	new_node->token = type;
	new_node->data = ft_strdup(value);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!(*data))
		(*data) = new_node;
	else
	{
		last_node = last_from_list(*data);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	free_list(t_token **data)
{
	t_token	*current;
	t_token	*temp;

	if (!data || !(*data))
		return ;
	current = *data;
	while (current)
	{
		temp = current->next;
		free(current->data);
		free(current);
		current = temp;
	}
	*data = NULL;
}

static void	tokenization(char *cmd)
{
	t_token	*data;
	t_type_cmd	type;
	int	i;
	int	start;

	i = 0;
	data = NULL;
	if (!cmd)
		return ;
	while (cmd[i] != '\0')
	{
		while (ft_isspace(cmd[i]))
			i++;
		start = i;
		if (cmd[i] == '<' && cmd[i+1] == '<')
		{
			type = HEREDOC;
			i +=2;
		}
		else if (cmd[i] == '<')
		{
			type = REDIRECT_IN;
			i++;
		}
		else if (cmd[i] == '>' && cmd[i+1] == '>')
		{
			type = APPEND;
			i+= 2;
		}
		else if (cmd[i] == '>')
		{
			type = REDIRECT_OUT;
			i++;
		}
		else if (cmd[i] == '|')
		{
			type = PIPE;
			i++;
		}
		else
		{
			type = CMD;
			while (cmd[i] != 0 && !(ft_isspace(cmd[i])) && cmd[i] != '<'
				&& cmd[i] != '>' && cmd[i] != '|')
				i++;
		}
		int token_length = i - start;

		printf("%s\n", cmd);
		if (token_length > 0)
		{
			char	*token = (char *)calloc((token_length + 1), sizeof(char));
			ft_strncpy(token, cmd + start, token_length);
			token[token_length] = '\0';
			printf("Token: %s\n", token);
			add_node(&data, type, token);
			free(token);
		}
	}
	if (data){
		print_token_list(data);
		free_list(&data);
	}
}

void	print_prompt(void)
{
	char	*prompt;
	char	*cmd;

	prompt = "minishell$ ";
	while (42)
	{

		cmd = readline(prompt);
		if (!cmd)
			break ;
		if (*cmd)
		{
			add_history(cmd);
			tokenization(cmd);
		}
		free(cmd);
	}
}

int	main(void)
{
	print_prompt();
	return (0);
}
