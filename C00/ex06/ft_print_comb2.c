/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:45:28 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/25 14:37:21 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	increment(int *nb1, int *nb2)
{
	(*nb2)++;
	if (*nb2 > 99)
	{
		(*nb1)++;
		*nb2 = *nb1 + 1;
	}
}

void	ft_print_comb2(void)
{
	int	nb1;
	int	nb2;

	nb1 = 0;
	nb2 = 1;
	while (nb1 <= 98)
	{
		if (nb1 < 10)
			write(1, "0", 1);
		ft_putnbr(nb1);
		write(1, " ", 1);
		if (nb2 < 10)
			write(1, "0", 1);
		ft_putnbr(nb2);
		increment(&nb1, &nb2);
		if (nb1 <= 98)
			write(1, ", ", 2);
	}
}
/*
int	main(void)
{
	ft_print_comb2();
}*/
