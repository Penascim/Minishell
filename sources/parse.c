/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:58:59 by thfranco          #+#    #+#             */
/*   Updated: 2024/07/04 20:30:04 by thfranco         ###   ########.fr       */
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

	node = calloc(1,sizeof(t_tree_node));
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

void print_tree(t_tree_node *node, int level) {
    if (node == NULL)
        return;

    // Print indentation based on the level of the tree
    for (int i = 0; i < level; i++)
        printf("  ");

    // Print the current node
    printf("Type: %d, Value: %s\n", node->type, node->value ? node->value : "NULL");

    // Recursively print left and right children
    if (node->left)
        print_tree(node->left, level + 1);
    if (node->right)
        print_tree(node->right, level + 1);
}

void	parse(t_token *data)
{
	t_tree_node *root = NULL;
	t_tree_node *current = NULL;
	t_tree_node *new_node = NULL;
	t_tree_node *temp = NULL;

	//print_token_list(data);
	while (data)
	{
		new_node = create_tree_node(data->token, data->value);
		if (!new_node)
		{
			perror("Failed to create tree node");
			exit(EXIT_FAILURE);
		}
		if(!root)
			root = current = new_node;
		else if (data->token == CMD || data->token == ARG
			|| data->token == ENV_VAR || data->token == EXPAND)
		{
			if (current->right)
			{
				temp = current->right;
				while (temp->left)
					temp = temp->left;
				temp->left = new_node;
			}
			else
				current->right = new_node;
		}
		else if (data->token == REDIRECT_IN || data->token == REDIRECT_OUT
			|| data->token == APPEND || data->token == HEREDOC || data->token == PIPE)
		{
			new_node->left = current;
			current = new_node;
			if (!root)
				root = current;
		}
		data = data->next;
	}
	printf("AQUIIII\n");
	//return (root);
	//print_token_list(data);
	print_tree(root, 0);
	free_tree(root);
}
