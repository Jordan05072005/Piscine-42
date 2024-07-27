/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:55:47 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/27 17:02:04 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	display_map(int tab[4][4]);

void	ft_put_4_from1(int tab[4][4], int *sol)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i >= 0 && i < 4)
			if (sol[i] == 1)
				tab[0][i] = 4;
		if (i >= 4 && i < 8)
			if (sol[i] == 1)
				tab[3][i - 4] = 4;
		if (i >= 8 && i < 12)
			if (sol[i] == 1)
				tab[i - 8][0] = 4;
		if (i >= 12 && i < 16)
                       if (sol[i] == 1)
                               tab[i - 12][3] = 4;
		i++;
	}
}

void	ft_put_4_from3_2(int tab[4][4], int *sol)
{
	int	i;

        i = 0;
        while (i < 16)
        {
                if (i >= 0 && i < 4)
                        if (sol[i] == 3 && sol[i + 4] == 2)
                                tab[2][i] = 4;
                if (i >= 4 && i < 8)
                        if (sol[i] == 3 && sol[i - 4] == 2)
                                tab[1][i - 4] = 4;
                if (i >= 8 && i < 12)
                        if (sol[i] == 3 && sol[i + 4] == 2)
                                tab[i - 8][2] = 4;
                if (i >= 12 && i < 16)
                       if (sol[i] == 3 && sol[i - 4] == 2)
                               tab[i - 12][1] = 4;
                i++;
        }
}

void	ft_print_from4(int tab[4][4], int nbr_start, int row_or_col)
{
	int	j;

	j = 0;
	if (row_or_col > 0)
		while (j < 4)
		{
			if (row_or_col == 1)
				tab[nbr_start][j] = j + 1;
			else 
				tab[j][nbr_start] = j + 1;
			j++;
		}
	else
		while (j > -4)
		{
			if (row_or_col == -1)
				tab[nbr_start][3 + j] = (-j) + 1;
			else 
				tab[3 + j][nbr_start] = (-j) + 1;  
			j--;
		}
}
		



void	ft_put_from4(int tab[4][4], int *sol)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i >= 0 && i < 4)
			if (sol[i] == 4)
				ft_print_from4(tab, i, 2);
		if (i >= 4 && i < 8)
			if (sol[i] == 4)
				ft_print_from4(tab, i - 4, -2);
		if (i >= 8 && i < 12)
			if (sol[i] == 4)
				ft_print_from4(tab, i - 8, 1);
		if (i >= 12 && i < 16) 
			if (sol[i] == 4)
				ft_print_from4(tab, i - 12, -1);
		i++;
	}
}



int	ft_count_int(int tab[4][4], int nb)
{
	int	row;
	int	col;
	int	result;

	row = 0;
        result = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tab[row][col] == nb)
				{
					result++;
				}
				col++;
		}
		row++;
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	int	tab[4][4] = {
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,2,0,0},
	};

	int sol[] = {3,3,0,0,
		2,3,0,0,
		0,0,0,0,
		0,0,0,0};

	ft_put_4_from1(tab, sol);
	ft_put_4_from3_2(tab, sol);
	ft_put_from4(tab, sol);
	display_map(tab);
	printf("\n%d\n", ft_count_int(tab, 2));
}*/
