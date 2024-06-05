/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:32:59 by thfranco          #+#    #+#             */
/*   Updated: 2023/11/04 11:33:05 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int n)
{
	int	len;

	len = 0;
	if (n < 1)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	check_sign(int n)
{
	int	nbr;

	nbr = 1;
	if (n < 0)
		nbr = nbr * -n;
	else
		nbr = nbr * n;
	return (nbr);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				sign;
	int				len;
	char			*str;

	sign = 0;
	len = n_len(n);
	nbr = check_sign(n);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (n < 0)
		sign = 1;
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	while (len--)
	{
		*(str + len) = 48 + nbr % 10;
		nbr /= 10;
	}
	if (sign)
		*(str) = 45;
	return (str);
}

/*int main() {
    int num = -12345; // Número inteiro para conversão
    char *str; // Ponteiro para a string resultante

    // Chama a função ft_itoa para converter o número em uma string
    str = ft_itoa(num);

    if (str) {
        // Imprime a string resultante
        printf("Número convertido: %s\n", str);

        // Libera a memória alocada para a string
        free(str);
    } else {
        printf("Erro na alocação de memória para a string.\n");
    }

    return 0;
}*/
