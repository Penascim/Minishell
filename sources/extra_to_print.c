/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_to_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:37:25 by thfranco          #+#    #+#             */
/*   Updated: 2024/07/09 11:38:20 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_tree(t_tree_node *node, int level)
{
	int	i;

	i = 0;
	if (node == NULL)
		return ;
	while (i < level)
	{
		printf("  ");
		i++;
	}
	printf("Type: %d, Value: %s\n", node->type,
		node->value ? node->value : "NULL");
	if (node->left)
		print_tree(node->left, level + 1);
	if (node->right)
		print_tree(node->right, level + 1);
}

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
