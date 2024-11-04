/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:52:19 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/05 11:44:56 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	comp;

	i = 0;
	comp = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			comp++;
		i++;
	}
	return (comp);
}

/*
int	test(char *str)
{
	if (str[0] == 'a')
		return (1);
	return (0);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	printf("%d", ft_count_if(av, ac, &test));
}*/
