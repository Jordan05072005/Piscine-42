/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:31:21 by hle-hena          #+#    #+#             */
/*   Updated: 2024/08/07 19:31:54 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	is_valid_char(t_map map, char c)
{
	if (c == map.obstacle || c == map.empty)
		return (1);
	return (0);
}

t_sqr	get_line(t_map map, int **list_sqr, int i)
{
	int		j;
	int		max_index;
	t_sqr	max;

	j = 0;
	max_index = 0;
	while (map.map[i][j] && is_valid_char(map, map.map[i][j]))
	{
		add_val(map, list_sqr, j, i);
		if (list_sqr[i][j] > list_sqr[i][max_index])
			max_index = j;
		j ++;
	}
	list_sqr[i][j] = -1;
	if (j != map.len_lines)
		list_sqr[0][0] = -2;
	max.y = i;
	max.x = max_index;
	max.val = list_sqr[i][max_index];
	return (max);
}

t_sqr	get_sqr(t_map map)
{
	t_sqr	max_sqr;
	t_sqr	temp_max_sqr;
	int		**list_sqr;
	int		i;
	int		error;

	i = -1;
	max_sqr.val = -1;
	list_sqr = malloc((map.nb_lines + 1) * sizeof(int *));
	while (map.map[++ i])
	{
		list_sqr[i] = ft_calloc_int((map.len_lines + 1), sizeof(int));
		if (i >= map.nb_lines || ft_strlen(map.map[i]) != map.len_lines)
			return (null_list(list_sqr, i), null_sqr());
		temp_max_sqr = get_line(map, list_sqr, i);
		if (temp_max_sqr.val > max_sqr.val)
			max_sqr = temp_max_sqr;
	}
	list_sqr[i] = malloc(sizeof(int));
	list_sqr[i][0] = -1;
	error = (list_sqr[0][0] == -2);
	free_list(list_sqr);
	if (i != map.nb_lines || error)
		return (null_sqr());
	return (max_sqr);
}
