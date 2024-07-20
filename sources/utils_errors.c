/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:48:54 by thfranco          #+#    #+#             */
/*   Updated: 2024/07/20 15:02:33 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_start_end(t_token *data)
{
	if (data->token == PIPE)
	{
		print_error("syntax error near unexpected token `", data->value);
		return (1);
	}
	while (data->next != NULL)
		data = data->next;
	if (data->next == NULL)
	{
		if (data->token == REDIRECT_IN || data->token == REDIRECT_OUT
			|| data->token == APPEND || data->token == HEREDOC)
		{
			print_error("syntax error near unexpected token `", "newline");
			return (1);
		}
	}
	return (0);
}

int	has_error(t_token *data)
{
	if (check_append(data) || check_redirect_in(data)
		|| check_redirect_out(data) || check_heredoc(data) || check_pipe(data)
		|| check_start_end(data))
		return (0);
	return (1);
}
