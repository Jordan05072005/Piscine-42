/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:46:39 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/05 18:22:49 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}
/*
int	sup(int	a, int b)
{
	if (a < b)
		return (-1);
	else if (b < a)
		return (1);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	int	nbr[] = {1, 2 , 3};
	int	nbr2[] = {0, 2, 1};
	
	printf("%d", ft_is_sort(nbr, 3, sup));
	printf("%d", ft_is_sort(nbr2, 3, &sup));
}
*/
