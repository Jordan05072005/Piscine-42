/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:32:26 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/27 17:54:42 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	error(int e);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_map(int tab[4][4])
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			ft_putchar(tab[x][y] + '0');
			if (y < 3)
			{
				ft_putchar(' ');
			}
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}

int	check_if_zero(int tab[4][4])
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tab[x][y] == 0)
			{
				error(1);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}
/*
int	main(void)
{
	int	tab[4][4];

	tab[0][0] = 0;
	tab[0][1] = 2;
	tab[0][2] = 3;
	tab[0][3] = 4;
	tab[1][0] = 4;
	tab[1][1] = 3;
	tab[1][2] = 2;
	tab[1][3] = 1;
	tab[2][0] = 3;
	tab[2][1] = 4;
	tab[2][2] = 1;
	tab[2][3] = 2;
	tab[3][0] = 4;
	tab[3][1] = 1;
	tab[3][2] = 2;
	tab[3][3] = 3;
	display_map(tab);
	check_if_zero(tab);
	return (0);
}
*/
