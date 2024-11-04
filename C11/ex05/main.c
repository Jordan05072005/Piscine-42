/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:34:59 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/05 18:31:53 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	doop(int a, int b, char operator, int (*f[])(int, int))
{
	int	nbr;

	nbr = 0;
	if (operator == '+')
		nbr = f[0](a, b);
	else if (operator == '-')
		nbr = f[1](a, b);
	else if (operator == '*')
		nbr = f[2](a, b);
	else
	{
		doop2(a, b, operator, f);
		return ;
	}
	ft_putnbr(nbr);
}

void	doop2(int a, int b, char operator, int (*f[])(int, int))
{
	int	nbr;

	nbr = 0;
	if (operator == '/')
	{
		if (f[3](a, b) == -1)
		{
			write(1, "Stop : division by zero", 24);
			return ;
		}
		nbr = f[3](a, b);
	}
	else if (operator == '%')
	{
		if (f[4](a, b) == -1)
		{
			write(1, "Stop : modulo by zero", 22);
			return ;
		}
		nbr = f[4](a, b);
	}
	ft_putnbr(nbr);
}

void	ft_fill(int (*f[])(int, int))
{
	f[0] = addition;
	f[1] = soustraction;
	f[2] = multiplication;
	f[3] = division;
	f[4] = modulo;
}

int	main(int ac, char **av)
{
	int	(*f[5])(int, int);
	int	nb1;
	int	nb2;

	ft_fill(f);
	if (ac == 4)
	{
		nb1 = ft_atoi(av[1]);
		nb2 = ft_atoi(av[3]);
		doop(nb1, nb2, av[2][0], f);
	}
}
