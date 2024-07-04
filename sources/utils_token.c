/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:51:59 by thfranco          #+#    #+#             */
/*   Updated: 2024/07/04 18:57:00 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_token_list(t_token *head)
{
	t_token	*current;

	current = head;
	printf("Lista de Tokens:\n");
	while (current != NULL)
	{
		printf("Token: %s\n", current->value);
		printf("Tipo: %d\n", current->token);
		current = current->next;
	}
}

t_token	*last_from_list(t_token *data)
{
	if (!data)
		return (NULL);
	while (data->next)
		data = data->next;
	return (data);
}

void	add_node(t_token **data, t_type_cmd type, char *value)
{
	t_token	*new_node;
	t_token	*last_node;

	if (!data)
		return ;
	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return ;
	new_node->token = type;
	new_node->value = ft_strdup(value);
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
		free(current->value);
		free(current);
		current = temp;
	}
	*data = NULL;
}
