/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:36:41 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/22 16:28:00 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
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
	char	str[] = "je suis pareil oui";
	char	str1[] = "je suis pareil oui";
	int		i;

	i = ft_strncmp(str, str1, 1844);
	printf("%d", i);
}*/
