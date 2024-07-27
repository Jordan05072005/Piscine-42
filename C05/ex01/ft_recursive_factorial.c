/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:06:59 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/23 18:11:51 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb > 1)
		return (nb * ft_recursive_factorial(nb - 1));
	return (1);
}
/*
#include <stdio.h>

int ft_recursive_factorial(int nb);

int	main(void)
{
	printf("0:%d\n", ft_recursive_factorial(-10));
	printf("0:%d\n", ft_recursive_factorial(-1));
	printf("1:%d\n", ft_recursive_factorial(0));
	printf("1:%d\n", ft_recursive_factorial(1));
	printf("3628800:%d\n", ft_recursive_factorial(10));
	printf("6:%d\n", ft_recursive_factorial(3));
}*/
