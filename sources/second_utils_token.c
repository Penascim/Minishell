/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_utils_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:18:46 by thfranco          #+#    #+#             */
/*   Updated: 2024/07/09 11:23:48 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	index_env(char *cmd, int i)
{
	if (cmd[i++] == '{')
		while (cmd[i] && cmd[i++] != '}')
			;
	else if (cmd[i++] == '(')
		while (cmd[i] && cmd[i++] != ')')
			;
	else
		while (cmd[i] && !ft_isspace(cmd[i++]))
			;
	return (i);
}
