/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:59:08 by hle-hena          #+#    #+#             */
/*   Updated: 2024/08/07 19:16:45 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	free_list(int **list_sqr)
{
	int	i;

	i = 0;
	while (list_sqr[i][0] != -1)
	{
		free(list_sqr[i]);
		i ++;
	}
	free(list_sqr[i]);
	free(list_sqr);
}

void	free_strs(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i ++;
	}
	free(str);
}
