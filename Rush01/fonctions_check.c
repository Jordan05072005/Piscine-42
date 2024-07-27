/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:23:32 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/27 14:23:30 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_tab_dup(int tab[4][4])
{
	int	i;
	int	j;
	int	row;

	i = 0;
	j = 1;
	row = 0;
	while (row < 4)
	{
		if (j == 4)
			j = (i++) + 1;
		if (i == 3)
		{
			row++;
			i = 0;
			j = i + 1;
		}
		if ((tab[row][i] == tab[row][j]
					|| tab[i][row] == tab[j][row]) && i != j)
			return (0);
		j++;
	}
	return (1);
}

int	check_row1(int tab[4][4], int *sol)
{
	int	i;
	int	counter;
	int	max;
	int	base;

	base = 0;
	while (base < 4)
	{
		max = tab[base][0];
		i = 1;
		counter = 1;
		while (i < 4)
		{
			if (tab[base][i] > max)
				counter++;
			i++;
		}
		if (counter != sol[8 + base])
			return (0);
		base++;
	}
	return (1);
}

int	check_row2(int tab[4][4], int *sol)
{
	int	i;
	int	counter;
	int	max;
	int	base;

	base = 0;
	while (base < 4)
	{
		max = tab[base][3];
		i = 3;
		counter = 1;
		while (i >= 0)
		{
			if (tab[base][i] > max)
				counter++;
			i--;
		}
		if (counter != sol[12 + base])
			return (0);
		base++;
	}
	return (1);
}

int	check_col1(int tab[4][4], int *sol)
{
	int	i;
	int	counter;
	int	max;
	int	base;

	base = 0;
	while (base < 4)
	{
		max = tab[0][base];
		i = 1;
		counter = 1;
		while (i < 4)
		{
			if (tab[i][base] > max)
				counter++;
			i++;
		}
		if (counter != sol[base])
			return (0);
		base++;
	}
	return (1);
}

int	check_col2(int tab[4][4], int *sol)
{
	int	i;
	int	counter;
	int	max;
	int	base;

	base = 0;
	while (base < 4)
	{
		max = tab[3][base];
		i = 3;
		counter = 1;
		while (i >= 0)
		{
			if (tab[i][base] > max)
				counter++;
			i--;
		}
		if (counter != sol[4 + base])
			return (0);
		base++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	int	tab[4][4] = {
		{4, 3, 2, 1} ,
		{3, 4, 2 , 1} ,
		{2, 3 , 4, 1} ,
		{1, 2, 3 ,4}
	};
	int     tab2[4][4] = {
               	{1, 2, 3, 4} ,
                {4, 1, 2 , 3} ,
                {4, 3 , 1, 2} ,
                {4, 3, 2 ,1}

	};

	int     tab3[4][4] = {
                {4, 3, 2, 1} ,
                {3, 4, 3, 2} ,
                {2, 2, 4, 3} ,
                {1, 1, 1 ,4}
	};
	int     tab4[4][4] = {
                {1, 1, 1, 4} ,
                {2, 1, 4, 3} ,
                {3, 4, 3, 2} ,
                {4, 3, 2 ,1}
        };

	int     tab5[4][4] = {
                {4, 2, 1, 3} ,
                {3, 1, 4, 2} ,
                {1, 3, 2, 4} ,
                {4, 4, 3 ,1}
        };
	

	int	sol[] = {1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4};
	printf("%d", check_row1(tab, sol));
	printf("%d", check_row2(tab2, sol));
	printf("%d", check_col1(tab3, sol));
	printf("%d", check_col2(tab4, sol));
	printf("%d", check_tab(tab5));


}
*/
