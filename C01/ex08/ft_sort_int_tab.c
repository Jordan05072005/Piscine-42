/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:56:09 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/25 13:50:16 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int *tab, int size, int indice)
{
	int	indice_mini;

	indice_mini = indice;
	while (indice < size)
	{
		if (tab[indice] < tab[indice_mini])
			indice_mini = indice;
		indice++;
	}
	return (indice_mini);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	indice;
	int	temp;

	i = 0;
	while (i < size)
	{
		indice = min(tab, size, i);
		temp = tab[i];
		tab[i] = tab[indice];
		tab[indice] = temp;
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int	tab[5] = {400, 50, 0, -78, 5};
	
	ft_sort_int_tab(tab, 5);
	printf("%d %d %d %d %d", tab[0], tab[1], tab[2], tab[3], tab[4]);
}*/
