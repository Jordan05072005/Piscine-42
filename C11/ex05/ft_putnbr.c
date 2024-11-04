/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:24:00 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/05 18:24:08 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putnbr(int nb)
{
	int	copy;

	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		ft_putnbr(147483648);
		return ;
	}
	else if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	copy = nb;
	if (nb >= 10)
	{
		copy = copy / 10;
		ft_putnbr(copy);
	}
	nb = '0' + nb % 10;
	write(1, &nb, 1);
}

/*
int	main(void)
{
	int	nbr;

	nbr = 10;
	ft_putnbr(nbr);
}
*/
