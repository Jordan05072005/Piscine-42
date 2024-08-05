/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:57:40 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/05 18:20:21 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
/*
int	test(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'i')
			return (1);
		i++;
	}
	return (0);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_any(argv, &test));
}*/
