/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:30:45 by thfranco          #+#    #+#             */
/*   Updated: 2024/07/09 17:16:51 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_bigger_then(t_token *data)
{
	while (data && data->next != NULL)
	{
		if (data->token == APPEND)
		{
			if (data->next->token == REDIRECT_IN || data->next->token == REDIRECT_OUT
				|| data->next->token == APPEND || data->next->token == HEREDOC
				|| data->next->token == PIPE)
			{
				print_error("syntax error near unexpected token `", data->next->value);
				return (1);
			}
		}
		if (data->token == REDIRECT_OUT)
		{
			if (data->next->token == REDIRECT_IN || data->next->token == REDIRECT_OUT
				|| data->next->token == APPEND || data->next->token == HEREDOC
				|| data->next->token == PIPE)
			{
				print_error("syntax error near unexpected token `", data->next->value);
				return (1);
			}
		}
		data = data->next;
	}
	return (0);
}

int	check_lower_then(t_token *data)
{
	while (data && data->next != NULL)
	{
		if (data->token == HEREDOC)
		{
			if (data->next->token == REDIRECT_IN || data->next->token == REDIRECT_OUT
				|| data->next->token == APPEND || data->next->token == HEREDOC
				|| data->next->token == PIPE)
			{
				print_error("syntax error near unexpected token `", data->next->value);
				return (1);
			}
		}
		if (data->token == REDIRECT_IN)
		{
			if (data->next->token == REDIRECT_IN || data->next->token == REDIRECT_OUT
				|| data->next->token == APPEND || data->next->token == HEREDOC
				|| data->next->token == PIPE)
			{
				print_error("syntax error near unexpected token `",data->next->value);
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
				print_error("syntax error near unexpected token `", data->next->value);
				return (1);
			}
		}
		data = data->next;
	}
	return (0);
}

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
		if (data->token == REDIRECT_IN
			|| data->token == REDIRECT_OUT || data->token == APPEND
			|| data->token == HEREDOC)
		{
			print_error("syntax error near unexpected token `", "newline");
			return (1);
		}
	}
	return (0);
}

int	has_error(t_token *data)
{
	if (check_bigger_then(data) || check_lower_then(data)
		|| check_pipe(data) || check_start_end(data))
		return (0);
	return (1);

}
