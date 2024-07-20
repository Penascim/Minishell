/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:24:06 by penascim          #+#    #+#             */
/*   Updated: 2024/07/20 17:47:35 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	S_QUOTE,
	D_QUOTE,
	COMMAND_SUBSTITUTION,
	NONE,
}						t_type_cmd;

typedef struct s_token
{
	char				*value;
	t_type_cmd			token;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_tree_node
{
	t_type_cmd			type;
	char				*value;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}						t_tree_node;

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

void					print_prompt(void);

// tokenization
t_token					*tokenization(char *cmd, t_token *data);
int						type_index(t_type_cmd type, char *cmd, int i);
char					*get_token(char *cmd, int i, int start);
t_type_cmd				find_type(char *cmd, int i, int first_token);
int						is_first_token(t_type_cmd type);

// utils_token
t_token					*last_from_list(t_token *data);
void					add_node(t_token **data, t_type_cmd type, char *value);
void					free_list(t_token **data);
t_token					*set_token_list(t_token *data, char *value_cmd,
							int type);

// index
int						index_envvar(char *cmd, int i);
int						index_single(char *cmd, int i);
int						index_double(char *cmd, int i);

// parse
t_tree_node				*create_tree_node(t_type_cmd type, char *value);
void					parse(t_token *data);
t_tree_node				*parse_command(t_token **data);
t_tree_node				*parse_expression(t_token **data);
void					free_tree(t_tree_node *node);

// execute
void					ft_free_tab(char **tab);
char					*get_path(char *cmd, char **envp);
void					print_error(char *msg, char *value);
void					ft_execute(char *av, char **envp);

// check_error
int						check_append(t_token *data);
int						check_redirect_out(t_token *data);
int						check_heredoc(t_token *data);
int						check_redirect_in(t_token *data);
int						check_pipe(t_token *data);

// handle_heredoc
void					heredoc(t_token *data);

// utils_errors
int						check_start_end(t_token *data);
int						has_error(t_token *data);

// extra_to_print
void					print_tree(t_tree_node *node, int level);
void					print_token_list(t_token *head);

#endif
