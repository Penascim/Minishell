/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:35:59 by thfranco          #+#    #+#             */
/*   Updated: 2024/06/21 13:03:23 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c);

int	ft_isspace(int c)
{
	if ((c >= 9 || c <= 13) && c == 32)
	{
		return (1);
	}
	return (0);
}