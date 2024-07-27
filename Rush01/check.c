/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:23:32 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/27 14:24:55 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	check(int tab[4][4], int *sol)
{
	if (check_tab_dup(tab) == 0)
		return (0);
	else if (check_row1(tab, sol) == 0)
		return (0);
	else if (check_row2(tab, sol) == 0)
                return (0);
	else if (check_col1(tab, sol) == 0)
                return (0);
	else if (check_col2(tab, sol) == 0)
                return (0);
	return (1);
}

