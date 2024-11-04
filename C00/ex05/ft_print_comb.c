/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:53:16 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/18 11:33:58 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printing(char n1, char n2, char n3)
{
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, &n3, 1);
	if (n1 != '7' || n2 != '8' || n3 != '9')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	nbr1;
	char	nbr2;
	char	nbr3;

	nbr1 = '0';
	nbr2 = '1';
	nbr3 = '2';
	while (nbr1 <= '7' || nbr2 <= '8' || nbr3 <= '9')
	{
		if (nbr3 > '9')
		{
			nbr3 = '0';
			nbr2++;
		}
		else if (nbr2 > '9')
		{
			nbr2 = '0';
			nbr1++;
		}
		else if (nbr1 < nbr2 && nbr2 < nbr3)
			printing(nbr1, nbr2, nbr3);
		nbr3++;
	}
}
