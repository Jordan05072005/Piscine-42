/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:46:33 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/27 18:52:20 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_int(int tab[4][4], int nb);

int	*ft_search_nb(int tab[4][4], int nb)
{
	int	*res;
	int	row;
	int	col;

	res = malloc(sizeof(int) * 4);
	row = 0;
	while (row < 4)
		res[row++] = -1;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tab[row][col] == nb)
				res[row] = col;
			col++;
		}
		row++;
	}
	return (res);
}

void	ft_fill_tab_int(int tab[4][4], int nb)
{
	int	*pt_res;
	int	row;
	int	col;
	int	i;

	i = 0;
	col = 1;
	if (ft_count_int(tab, 4) != 3)
		return ;
	pt_res = ft_search_nb(tab, nb);
	while (i < 4)
	{
		if (pt_res[i] == -1)
			row = i;
		if (col == pt_res[i])
		{
			col++;
			i = -1;
		}
		i++;
	}
	tab[row][col] = nb;
	free(pt_res);
}

int	ft_one_0(int tab[4][4], int row_or_col,int nb)
{
	int	position;
	int	i;

	position = -1;
	i = 0;
	while (i < 4)
	{
		if (tab[nb][i] == 0 && row_or_col == 1)
		{
			
			if (position != -1)
				return (-1);
			position = i;
		}
		if (tab[i][nb] == 0 && row_or_col == 2)
		{	
			if (position != -1)
				return (-1);
			position = i;
		}
		i++;
	}
	return (position);
}

void	ft_fill_tab_one_case(int tab[4][4])
{
	int	i;
	int	sum;

	i = 0;
	while (i < 4)
	{
		if (ft_one_0(tab, 1, i) != -1)
		{
			sum = tab[i][0] +tab[i][1] +tab[i][2] +tab[i][3];
			tab[i][ft_one_0(tab, 1, i)] = 10 - sum;
		}
		if (ft_one_0(tab, 2, i) != -1)
		{
			sum = tab[0][i] +tab[1][i] +tab[2][i] +tab[3][i];
			tab[ft_one_0(tab, 2, i)][i] = 10 - sum;
		}
		i++;
	}
}
/*
int     display_map(int tab[4][4]);
#include <stdio.h>

int     main(void)
{
        int     tab[4][4] = {
        {4,3,2,0},
        {2,4,0,0},
        {1,0,0,0},
        {0,2,4,0},
        };

	ft_fill_tab_int(tab, 4);
	ft_fill_tab_one_case(tab);
	display_map(tab);
}
*/
