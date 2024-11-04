/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:30:05 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/19 11:50:05 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp1;
	int	first;

	first = 0;
	size--;
	while (first < size)
	{
		temp1 = tab[first];
		tab[first] = tab[size];
		tab[size] = temp1;
		first++;
		size--;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int	tabl[] = { 1, 2, 2, 4, 5, 8};

	ft_rev_int_tab(tabl,6);
	printf("%d%d%d%d%d%d",tabl[0],tabl[1],tabl[2],tabl[3],tabl[4],tabl[5]);
}
*/
