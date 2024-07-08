/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:58:59 by thfranco          #+#    #+#             */
/*   Updated: 2024/07/08 17:33:54 by thfranco         ###   ########.fr       */
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

static t_tree_node *parse_command(t_token **data) {
    if (*data == NULL) return NULL;

    t_tree_node *node = create_tree_node((*data)->token, (*data)->value);
    *data = (*data)->next;

    // Parse arguments
    t_tree_node *current = node;
    while (*data && ((*data)->token == ARG || (*data)->token == ENV_VAR)) {
        t_tree_node *arg_node = create_tree_node((*data)->token, (*data)->value);
        current->right = arg_node; // Link argument to the command
        current = arg_node;
        *data = (*data)->next;
    }

    return node;
}


// Function to parse an expression
t_tree_node *parse_expression(t_token **data) {
    t_tree_node *left_node = parse_command(data);

    while (*data && ((*data)->token == PIPE || (*data)->token == REDIRECT_IN ||
                     (*data)->token == REDIRECT_OUT || (*data)->token == APPEND ||
                     (*data)->token == HEREDOC)) {

        int operator_type = (*data)->token;
        char *value = (*data)->value;
        *data = (*data)->next;

        t_tree_node *operator_node = create_tree_node(operator_type, value);
        operator_node->left = left_node;

        // Parse the right side of the operator
        operator_node->right = parse_command(data);

        left_node = operator_node; // Update left_node to the new operator node
    }

    return left_node;
}


// Main parsing function
void parse(t_token *data) {
    t_tree_node *root = parse_expression(&data);

    printf("Tree Construction Complete\n");
    print_tree(root, 0);
    free_tree(root);
}
