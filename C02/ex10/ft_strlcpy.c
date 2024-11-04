/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:24:43 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/22 11:47:09 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (str_len(src));
	i = 0;
	size--;
	while (src[i] != '\0' && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (str_len(src));
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[6] = "coucou";
	char	str2[7] = "";
	unsigned int	i;

	i = ft_strlcpy(str2, str, 0);
	printf("%s\n%d",str2,i);
}*/
