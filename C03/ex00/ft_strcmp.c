/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:05:03 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/22 16:25:56 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "iii";
	char	str2[] = "ii";
	int		i;

	i = ft_strcmp(str, str2);
	printf("%d", i);
}*/
