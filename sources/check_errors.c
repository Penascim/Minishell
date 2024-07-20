/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:30:45 by thfranco          #+#    #+#             */
/*   Updated: 2024/07/20 15:02:18 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_append(t_token *data)
{
	while (data && data->next != NULL)
	{
		if (data->token == APPEND)
		{
			if (data->next->token == REDIRECT_IN
				|| data->next->token == REDIRECT_OUT
				|| data->next->token == APPEND || data->next->token == HEREDOC
				|| data->next->token == PIPE)
			{
				print_error("syntax error near unexpected token `",
					data->next->value);
				return (1);
			}
		}
		data = data->next;
	}
	return (0);
}

int	check_redirect_out(t_token *data)
{
	while (data && data->next != NULL)
	{
		if (data->token == REDIRECT_OUT)
		{
			if (data->next->token == REDIRECT_IN
				|| data->next->token == REDIRECT_OUT
				|| data->next->token == APPEND || data->next->token == HEREDOC
				|| data->next->token == PIPE)
			{
				print_error("syntax error near unexpected token `",
					data->next->value);
				return (1);
			}
		}
		data = data->next;
	}
	return (0);
}

int	check_heredoc(t_token *data)
{
	while (data && data->next != NULL)
	{
		if (data->token == HEREDOC)
		{
			if (data->next->token == REDIRECT_IN
				|| data->next->token == REDIRECT_OUT
				|| data->next->token == APPEND || data->next->token == HEREDOC
				|| data->next->token == PIPE)
			{
				print_error("syntax error near unexpected token `",
					data->next->value);
				return (1);
			}
		}
		data = data->next;
	}
	return (0);
}

int	check_redirect_in(t_token *data)
{
	while (data && data->next != NULL)
	{
		if (data->token == REDIRECT_IN)
		{
			if (data->next->token == REDIRECT_IN
				|| data->next->token == REDIRECT_OUT
				|| data->next->token == APPEND || data->next->token == HEREDOC
				|| data->next->token == PIPE)
			{
				print_error("syntax error near unexpected token `",
					data->next->value);
				return (1);
			}
		}
		data = data->next;
	}
	return (0);
}

int	check_pipe(t_token *data)
{
	while (data && data->next != NULL)
	{
		if (data->token == PIPE)
		{
			if (data->next->token == PIPE)
			{
				print_error("syntax error near unexpected token `",
					data->next->value);
				return (1);
			}
		}
		data = data->next;
	}
	return (0);
}
