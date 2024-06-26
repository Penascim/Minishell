/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:15:49 by penascim          #+#    #+#             */
/*   Updated: 2024/06/26 14:28:39 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	print_prompt(void)
{
	char	*prompt;
	char	*cmd;

	prompt = "minishell$ ";
	while (42)
	{
		cmd = readline(prompt);
		if (!cmd)
            cmd = ft_strdup("exit");
		if (*cmd)
		{
			add_history(cmd);
			tokenization(cmd);
		}
		free(cmd);
	}
	rl_clear_history();
}

int	main(void)
{
	print_prompt();
	return (0);
}
