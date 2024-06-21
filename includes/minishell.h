/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:24:06 by penascim          #+#    #+#             */
/*   Updated: 2024/06/21 15:21:39 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <unistd.h>

typedef enum e_type
{
	CMD,          // 0
	ARG,          // 1
	REDIRECT_IN,  // 2
	REDIRECT_OUT, // 3
	PIPE,         // 4
	HEREDOC,      // 5
	APPEND,       // 6
	EXPAND,       // 7
}					t_type_cmd;

typedef struct s_token
{
	char			*data;
	t_type_cmd		token;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

void				print_prompt(void);
#endif
