/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:48:25 by hle-hena          #+#    #+#             */
/*   Updated: 2024/08/07 10:45:47 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (a > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

void	add_val(t_map map, int **tab, int x, int y)
{
	if (map.map[y][x] == map.obstacle)
		tab[y][x] = 0;
	else if (y == 0 || x == 0)
		tab[y][x] = 1;
	else
		tab[y][x] = ft_min(tab[y][x - 1], tab[y - 1][x],
				tab[y - 1][x - 1]) + 1;
}
