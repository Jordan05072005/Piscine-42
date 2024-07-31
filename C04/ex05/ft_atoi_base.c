/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:23:30 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/30 10:33:38 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_in_base(char *base, char c);

int	ft_find_max_indice(char *str, char *base)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_in_base(base, str[i] == 0))
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

int	test_base(char *base)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	while (base[size])
		size++;
	if (size <= 1)
		return (0);
	i = 0;
	while (i < size)
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == 32
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
	if (base == NULL || test_base(base) == 0)
		return (0);
	while (str[i] == 32 || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signe++;
	max_indice = ft_find_max_indice(&str[i], base);
	while (ft_is_in_base(base, str[i]) == 1 && str[i])
	{
		ft_increment_nbr(base, str[i], &nbr, -1 + max_indice--);
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
	printf("45:%d\n", ft_atoi_base("101101", "01"));
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
