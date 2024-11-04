/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:18:39 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/25 14:35:45 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	print_tab(char *tab, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		write(1, &tab[i], 1);
		i++;
	}
	if (tab[0] < ('9' - n))
		write(1, ", ", 2);
}

void	ft_croissance(char *tab, int i, int n)
{
	int	j;

	j = 1;
	while ((i + j) <= n)
	{
		tab[i + j] = tab[i] + j;
		j++;
	}
}

void	increment(char	*tab, int n)
{
	int	i;

	i = n;
	tab[n]++;
	while (tab[n] < tab[n - 1])
		tab[n]++;
	while (i > 0)
	{
		if (tab[i] > ('9' - (n - i)))
		{
			tab[i - 1]++;
			tab[i] = tab[i - 1] + 1;
			if (i != n)
				ft_croissance(tab, i, n);
		}
		i--;
	}
}

void	ft_print_combn(int n)
{
	char	tab[10];
	int		i;

	i = 0;
	while (i < n)
	{
		tab[i] = '0' + i;
		i++;
	}
	n--;
	while (tab[0] < ('9' - n))
	{
		print_tab(tab, n);
		increment(tab, n);
	}
	print_tab(tab, n);
}
/*
int	main(void)
{
	ft_print_combn(5);
}*/
