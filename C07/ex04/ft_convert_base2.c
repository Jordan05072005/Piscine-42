/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:23:30 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/31 15:48:45 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_is_in_base(char *base, char c);
int	ft_strlen(char *str);

int	test_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base == NULL || ft_strlen(base) <= 1)
		return (0);
	while (i < ft_strlen(base))
	{
		if (base[i] == '-' || base[i] == '+'
			|| (base[i] >= '\t' && base[i] <= '\r'))
			return (0);
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_find_max_indice(char *str, char *base)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_in_base(base, str[i]) == 1 && str[i + 1] == '\0')
			return (i);
		if (ft_is_in_base(base, str[i]) == 0)
			return (i - 1);
		i++;
	}
	return (i);
}

int	ft_is_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_increment_nbr(char *base, char nb, long *nbr, int indice_nb)
{
	int	i;
	int	indice;
	int	j;
	int	res;

	i = 0;
	res = 1;
	j = 0;
	while (base[i])
	{
		if (nb == base[i])
			indice = i;
		i++;
	}
	if ((indice_nb) != 0)
	{
		while (j < indice_nb)
		{
			res = res * i;
			j++;
		}
	}
	*nbr = *nbr + (indice * res);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		signe;
	int		max_indice;
	long	nbr;

	signe = 0;
	nbr = 0;
	i = 0;
	if (base == NULL || str == NULL || test_base(base) == 0)
		return (0);
	while (str[i] == 32 || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signe++;
	max_indice = ft_find_max_indice(&str[i], base);
	while (ft_is_in_base(base, str[i]) == 1 && str[i])
	{
		ft_increment_nbr(base, str[i], &nbr, max_indice--);
		i++;
	}
	if (signe % 2 == 0)
		return (nbr);
	return (-nbr);
}
/*
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	printf("45:%d\n", ft_atoi_base("       	 	072b4", "0123456789"));
	printf("42:%d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("-42:%d\n", ft_atoi_base("   --------+-2a", "0123456789abcdef"));
	printf("42:%d\n", ft_atoi_base("   -+-2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+- 2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-z", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", ""));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "+-0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "\t01"));
}*/
