/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:16:21 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/05 18:19:21 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*tab2;
	int	i;

	tab2 = malloc(sizeof(int) * (length));
	i = 0;
	while (i < length)
	{
		tab2[i] = (*f)(tab[i]);
		i++;
	}
	return (tab2);
}
/*
int	plus1(int nbr)
{
	return (nbr + 1);
}

#include <stdio.h>

int main(void)
{
	int	tab[4] = {8, 10 ,53 ,62};
	int	i;
	int	*tab2;

	i = 0;
	tab2 = ft_map(tab, 4, &plus1);
	while (i < 4)
	{
		printf("%d\n",tab2[i]);
		i++;
	}
}
*/
