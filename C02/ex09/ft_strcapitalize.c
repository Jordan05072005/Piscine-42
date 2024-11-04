/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:00:26 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/21 14:10:31 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lowercase(char str)
{
	if (str < 'a' || str > 'z')
		return (0);
	return (1);
}

int	ft_char_is_uppercase(char str)
{
	if (str < 'A' || str > 'Z')
		return (0);
	return (1);
}

int	ft_char_is_alpha_and_numeric(char str)
{
	if ((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z'))
		return (1);
	else if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && ft_char_is_lowercase(str[i]))
			str[i] -= 32;
		else if (ft_char_is_alpha_and_numeric(str[i - 1]) == 0)
		{
			if (ft_char_is_lowercase(str[i]) == 1)
				str[i] -= 32;
		}
		else
		{
			if (ft_char_is_uppercase(str[i]) == 1)
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "sAlAt Je suis 42player jean-louis+charle 82Lou";

	ft_strcapitalize(str);
	printf("%s", str);
}*/
