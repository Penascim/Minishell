/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:58:59 by thfranco          #+#    #+#             */
/*   Updated: 2024/08/03 19:36:12 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_tree(t_tree_node *node)
{
	if (node == NULL)
		return ;
	free_tree(node->left);
	free_tree(node->right);
	free(node);
}

t_tree_node	*create_tree_node(t_type_cmd type, char *value)
{
	t_tree_node	*node;

	node = calloc(1, sizeof(t_tree_node));
	if (!node)
	{
		perror("Failed to allocate memory for tree node");
		return (NULL);
	}
	node->type = type;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
 }
int is_operator(t_type_cmd token) {
    return (token == PIPE || token == REDIRECT_IN || token == REDIRECT_OUT ||
           token == APPEND || token == HEREDOC );
}

t_token *get_last_token(t_token *data)
{
	t_token *current;

	current = data;
	while (current->next)
		current = current->next;
	return (current);
}

// void	get_command(t_token *data)
// {
// 	int token;
// 	char *value;

// 	value = NULL;

// 	if (is_operator(data->token) || is_operator(data->prev->token))
// 	{
// 		if (is_first_token(data->token))
// 			data = data->next;
// 		while (data && (data->token == CMD || (data->token == ENV_VAR)))
// 		{
// 			token = data->token;
// 			value = ft_strjoin(value, data->value);
// 			data = data->next;
// 		}
// 	}
// 	if (is_operator(data->next->token))
// 	{
// 		while (data && (data->prev->token == CMD || (data->prev->token == ENV_VAR)))
// 			data = data->prev;
// 	}

// }


//working
t_tree_node	*parse_command(t_token **data)
{
	t_tree_node	*node;
	t_tree_node	*current;
	t_tree_node	*arg_node;

	if (*data == NULL)
		return (NULL);
	node = create_tree_node((*data)->token, (*data)->value);
	*data = (*data)->prev;
	current = node;
	while (*data && ((*data)->token == CMD || (*data)->token == ENV_VAR))
	{
		arg_node = create_tree_node((*data)->token, (*data)->value);
		current->left = arg_node;
		current = arg_node;
		*data = (*data)->prev;
	}
	return (node);
}

t_tree_node	*parse_expression(t_token **data)
{
	t_tree_node	*right_node;
	int			operator_type;
	char		*value;
	t_tree_node	*operator_node;

	right_node = parse_command(data);
	while (*data && ((*data)->token == PIPE || (*data)->token == REDIRECT_IN
			|| (*data)->token == REDIRECT_OUT || (*data)->token == APPEND
			|| (*data)->token == HEREDOC))
	{
		operator_type = (*data)->token;
		value = (*data)->value;
		*data = (*data)->prev;
		operator_node = create_tree_node(operator_type, value);
		operator_node->right = right_node;
		operator_node->left = parse_command(data);
		right_node = operator_node;
	}
	return (right_node);
}

void	parse(t_token *data)
{
	t_tree_node	*root;
	t_token		*last_token;

	last_token = get_last_token(data);
	root = parse_expression(&last_token);
	printf("Tree Construction Complete\n");
	print_tree(root, 0);
	free_tree(root);
}

