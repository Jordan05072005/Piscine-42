/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:17:51 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/27 15:41:44 by dacarate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdlib.h>


void	display_map(int **tab);

void	ft_putchar(char c);

int	check_if_zero(int **tab);


int	error(int e)
{
	if (e == 1)
		write(1, "Error\n", 6);
	return (1);
}
/*       /       /       /
4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
0123456789012345678901234567890123456
*/

char	is_input_good(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if ((i % 2) == 0)
		{
			if (input[i] < '1' && input[i] > '4')
				return ('n');
			else if ((i >= 8 && i <= 14) || i >= 22)
			{
				if ((input[i] + input[i - 8] - 96 < 3)
					|| (input[i] + input[i - 8] - 96 > 5))
					return ('n');
			}
		}
		else if (i % 2 == 1)
			if (input[i] != ' ')
				return ('n');
		i++;
	}
	if (i != 31)
		return ('n');
	return ('y');
}

int	**make_tab(int size)
{
	int	i;
	int	j;
	int	**tab;

	tab = malloc(size * sizeof(int *));
	i = 0;
	while (i < size)
	{
		tab[i] = malloc(size * sizeof(int));
		j = 0;
		while (j < size)
		{
			tab[i][j] = 0;
			j++ ;
		}
		i++ ;
	}
	return(tab);
}
void	free_tab(int **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++ ;
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	int	**tab;

	if (argc != 2 || is_input_good(argv[1]) == 'n')
		return (error(1));
	tab = make_tab(4);
	display_map(tab);
	check_if_zero(tab);
	return(0);
}
