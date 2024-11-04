/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:28:14 by hle-hena          #+#    #+#             */
/*   Updated: 2024/08/07 19:28:06 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	get_solution_file(char *filename)
{
	t_map	map;
	t_sqr	sqr_max;

	map = get_file(filename);
	if (map.nb_lines == -2)
		return (ft_puterror("map error"));
	sqr_max = get_sqr(map);
	if (sqr_max.val == -1)
	{
		free_strs(map.map);
		return (ft_puterror("map error"));
	}
	fill_sqr(sqr_max, map);
	ft_write_tab(map);
	free_strs(map.map);
}

void	get_solution_stdin(void)
{
	t_map	map;
	t_sqr	sqr_max;

	map = get_stdin();
	if (map.nb_lines == -2)
		return (ft_puterror("map error"));
	sqr_max = get_sqr(map);
	if (sqr_max.val == -1)
	{
		free_strs(map.map);
		return (ft_puterror("map error"));
	}
	fill_sqr(sqr_max, map);
	ft_write_tab(map);
	free_strs(map.map);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
		{
			get_solution_file(av[i]);
			if (i + 1 != ac)
				ft_putstr("\n");
			i ++;
		}
	}
	else
	{
		get_solution_stdin();
	}
}
