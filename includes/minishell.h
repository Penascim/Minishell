/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:24:06 by penascim          #+#    #+#             */
/*   Updated: 2024/06/26 14:20:45 by thfranco         ###   ########.fr       */
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

void				print_prompt(void);
// tokenization
void				tokenization(char *cmd);
int					type_index(t_type_cmd type, char *cmd, int i);
t_token				*get_token(char *cmd, int i, int start, t_type_cmd type);
t_type_cmd			find_type(char *cmd, int i);

// utils_tokenization
void				print_token_list(t_token *head);
t_token				*last_from_list(t_token *data);
void				add_node(t_token **data, t_type_cmd type, char *value);
void				free_list(t_token **data);
#endif
