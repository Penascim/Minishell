/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:15:49 by penascim          #+#    #+#             */
/*   Updated: 2024/06/20 12:01:03 by thfranco         ###   ########.fr       */
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


static void	tokenization(char *cmd)
{
	//t_token	data;
	t_type_cmd	type;
	int	i;
	int	start;

	i = 0;
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
			while (cmd[i] != 0 && !ft_isspace(cmd[i]) && cmd[i] != '<'
				&& cmd[i] != '>' && cmd[i] != '|')
				i++;
			i++;
		}
	}

}

void	print_prompt(void)
{
	char	*prompt;
	char	*cmd;

	prompt = "minishell$";
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
