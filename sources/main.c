/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:15:49 by penascim          #+#    #+#             */
/*   Updated: 2024/07/20 18:00:15 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

static void	run(char *prompt)
{
	char	*cmd;
	t_token	*tokens;

	while (42)
	{
		cmd = readline(prompt);
		if (!cmd)
			cmd = ft_strdup("exit");
		if (*cmd)
		{
			add_history(cmd);
			tokens = tokenization(cmd, tokens);
			print_token_list(tokens);
			if (has_error(tokens))
			{
				heredoc(tokens);
				parse(tokens);
			}
			free_list(&tokens);
		}
		free(cmd);
	}
	rl_clear_history();
}

void	print_prompt(void)
{
	char	*prompt;

	prompt = "minishell$ ";
	run(prompt);
}

int	main(void)
{
	print_prompt();
	return (0);
}
