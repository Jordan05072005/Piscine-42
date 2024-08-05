/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:58:16 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/05 18:18:29 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}
/*
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

int	main(void)
{
	int	tab[4] = {4, 5, 4 , 32};

	ft_foreach(tab, 4, &ft_putnbr);
}*/
