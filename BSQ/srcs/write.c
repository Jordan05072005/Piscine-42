/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:46:24 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/07 14:25:03 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_write_tab(t_map map)
{
	int	row;

	row = 0;
	while (map.map[row])
	{
		write(1, map.map[row], map.len_lines);
		write(1, "\n", 1);
		row++;
	}
}

void	fill_sqr(t_sqr max, t_map map)
{
	int	x;
	int	y;

	x = max.x - (max.val - 1);
	y = max.y - (max.val - 1);
	while (x <= max.x || y < max.y)
	{
		if (x > max.x)
		{
			x = max.x - (max.val - 1);
			y++;
		}
		map.map[y][x] = map.full;
		x++;
	}
}
