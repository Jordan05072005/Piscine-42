/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:43:58 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/25 10:01:01 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return ((int)(s1[i] - s2[i]));
		else if (s1[i] < s2[i])
			return (-(int)(s2[i] - s1[i]));
		i++;
	}
	return (0);
}

int	indice_sort(char **str)
{
	int	min;
	int	i;

	min = 0;
	i = 1;
	while (str[i])
	{
		if (ft_strcmp(str[min], str[i]) > 0)
			min = i;
		i++;
	}
	return (min);
}

int	main(int argc, char **argv)
{
	int	mini;

	argc--;
	while (argc > 0)
	{
		mini = indice_sort(&argv[1]);
		write(1, argv[mini + 1], ft_strlen(argv[mini + 1]));
		write(1, "\n", 1);
		argv[mini + 1][0] = 127;
		argc--;
	}
}
