/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:05:27 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/24 15:56:16 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	test_ligne(char *str, char value, int indice, int indice_base)
{
	printf("|%c,%d,%c|",value, indice,str[indice]);
	if (value >= 9 && indice <= 0 && str[indice] == value)
		return (-1);
	else if (indice == 0  && str[indice] != value)
		return (value);
	else if (str[indice] == value)
		return test_ligne(str, value + 1, indice_base , indice_base);
	else if (str[indice] != value)
		return test_ligne(str, value , indice - 1 , indice_base);
	return (8);
}



/*
int	ft_placing_not_snip(char *str, int indice)
{

}

int ft_ten_queens_puzzle(void)
{
	char    str[] = "0257948136";
	int	i;
	int	boole;


        while (str != "9742051863")
        {
		boole = ft_placing_not_snip(str, 5);
		i = 5;
		while (boole == -1)
		{
			i--;
			if (i == 0)
				str[i]++;
			else
				boole = ft_placing_not_snip(str, i);
		}
		ft_placing_other_not_snip(str, i + 1);
	}

}
*/
#include <stdio.h>

int	main(void)
{
	char	str[5] = "93765";
	printf("%d",test_ligne(str, '5', 3, 3));
}
