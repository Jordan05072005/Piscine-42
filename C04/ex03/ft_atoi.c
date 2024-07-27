/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:23:30 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/23 17:46:12 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_space_number_signe(char c, int *phase)
{
	if (*phase == 1 || *phase == 0)
	{
		if ((c == '+' || c == '-'))
		{
			*phase = 1;
			return (1);
		}
	}
	if (*phase == 0)
	{
		if (c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
			return (1);
		else if (c == 32)
			return (1);
	}
	if (c >= '0' && c <= '9')
	{
		*phase = 2;
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	phase;
	int	nbr;
	int	signe;

	signe = 0;
	nbr = 0;
	i = 0;
	phase = 0;
	while (str[i] != '\0' && ft_char_is_space_number_signe(str[i], &phase) == 1)
	{
		if (str[i] == '-')
			signe++;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			nbr = (nbr * 10) + (str[i] - '0');
		}
		i++;
	}
	if (signe % 2 == 0)
		return (nbr);
	return (-nbr);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("42:%d\n", ft_atoi("  \n  42t4457"));
	printf("-42:%d\n", ft_atoi(" --+-42sfs:f545"));
	printf("0:%d\n", ft_atoi("\0 1337"));
	printf("0:%d\n", ft_atoi("-0"));
	printf("0:%d\n", ft_atoi(" - 1 3 2 5 6 3 2 1 6 7"));
	printf("-1325632167:%d\n", ft_atoi("-1325632167"));
	printf("-100:%d\n", ft_atoi("-100"));
	printf("min:%d\n", ft_atoi("\t---+2147483648"));
	printf("max:%d\n", ft_atoi("\v2147483647"));
}*/
