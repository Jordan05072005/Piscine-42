/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:11:07 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/23 17:42:40 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
        int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_index_of(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);

}

int	ft_char_is_space_number_signe(char c, int *phase, char *base)
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
	if (ft_index_of(c, base) != -1)
	{
		*phase = 2;
		return (1);
	}
	return (0);
}

int	check_indice_max(char *base)
{
	int	i;
	int	phase;

	i = 0;
	while (base[i] != '\0')
	{
		phase = 0;
		if (ft_char_is_space_number_signe(base[i], &phase, base) == 0)
			return (i-1);
		i++;
	}
}

int	puissance(int	nbr1, int puiss)
{
	int	i;
	int	nbr;

	i = 1;
	nbr = 1;
	if (puiss == 0)
		return (1);
	while (i != puiss)
	{
		nbr = nbr * nbr1;
		i++;
	}
	return (nbr);
}



int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	phase;
	int	nbr;
	int	signe;

	signe = 0;
	nbr = 0;
	i = 0;
	phase = 0;
	while (str[i] != '\0' && ft_char_is_space_number_signe(str[i], &phase, base) == 1)
	{
		if (str[i] == '-')
			signe++;
		else if (ft_index_of(str[i], base) != -1)
		{
			nbr = nbr + ((ft_index_of(str[i],base)) * ( puissance(ft_strlen(base),check_indice_max(base) - i)));
		}
		i++;
	}
	if (signe % 2 == 0)
		return (nbr);
	return (-nbr);
}

#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	printf("42:%d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("-42:%d\n", ft_atoi_base("   --------+-2a", "0123456789abcdef"));
	printf("42:%d\n", ft_atoi_base("   -+-2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+- 2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-z", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", ""));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "+-0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "\t01"));
}
