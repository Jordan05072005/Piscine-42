/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:10:09 by hle-hena          #+#    #+#             */
/*   Updated: 2024/08/07 18:15:19 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	null_list(int **tab, int i)
{
	tab[i][0] = -1;
	free_list(tab);
}

t_sqr	null_sqr(void)
{
	t_sqr	sqr;

	sqr.val = -1;
	return (sqr);
}

t_map	null_map(char **str)
{
	t_map	map;

	map.map = str;
	map.nb_lines = -2;
	return (map);
}

void	ft_puterror(char *str)
{
	while (*str)
		write(2, &*str++, 1);
	write(1, "\n", 1);
}
