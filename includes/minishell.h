/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penascim <penascim@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:24:06 by penascim          #+#    #+#             */
/*   Updated: 2024/06/18 07:50:57 by penascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"

typedef struct	s_string
{
	char			*str;
	int				index;
	struct s_string	*next;
}				t_string;


// libft auxiliar list functions
void    ft_lstadd_back(t_string **str, t_str *new);
void    ft_lstadd_front(t_string **str, t_str *new);
int     ft_lstsize(t_string *str);
t_list  *ft_lstlast(t_string *str);
t_list  *ft_lstnew(int value);
long    ft_atoi(const char *ptr);

	/* oiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiieeeeeeeeeeeeeeeeeeee */

#endif
