/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:24:06 by penascim          #+#    #+#             */
/*   Updated: 2024/07/04 19:16:50 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

typedef enum e_type
{
	CMD,
	ARG,
	REDIRECT_IN,
	REDIRECT_OUT,
	PIPE,
	HEREDOC,
	APPEND,
	EXPAND,
	ENV_VAR,
}					t_type_cmd;

typedef struct s_token
{
	char			*value;
	t_type_cmd		token;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_tree_node
{
	t_type_cmd	type;
	char	*value;
	struct s_tree_node *left;
	struct s_tree_node	*right;
}					t_tree_node;

// typedef struct s_scommand
// {
// 	char *command;
// 	char **argument;
// 	t_redirect *redirect;
// }					t_s_command;

// typedef struct s_command
// {
// 	t_s_command	*first;
// }					t_command;

// typedef	struct s_redirect
// {
// 	t_type_cmd	type;
// 	char	*filename;
// 	struct s_redirect *next;
// }	t_redirect;


void				print_prompt(void);
// tokenization
t_token				*tokenization(char *cmd);
int					type_index(t_type_cmd type, char *cmd, int i);
char	*get_token(char *cmd, int i, int start);
t_type_cmd	find_type(char *cmd, int i, int first_token);
int	is_first_token(t_type_cmd type);
// utils_tokenization
void				print_token_list(t_token *head);
t_token				*last_from_list(t_token *data);
void				add_node(t_token **data, t_type_cmd type, char *value);
void				free_list(t_token **data);


//parse
t_tree_node	*create_tree_node(t_type_cmd type, char *value);
void	parse(t_token *data);

#endif
