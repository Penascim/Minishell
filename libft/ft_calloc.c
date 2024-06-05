/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:30:13 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/05 15:56:22 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elements, size_t size)
{
	size_t	total;
	void	*allocated_memory;

	total = n_elements * size;
	allocated_memory = malloc(total);
	if (allocated_memory != NULL)
		ft_memset(allocated_memory, 0, total);
	return (allocated_memory);
}
