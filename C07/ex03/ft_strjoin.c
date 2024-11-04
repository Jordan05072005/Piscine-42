/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:26:36 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/31 18:35:50 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	size_dest;
	int	i;

	i = 0;
	size_dest = 0;
	while (dest[size_dest] != '\0')
		size_dest++;
	while (src[i] != '\0')
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_size_all(int size, char **strs, char *sep)
{
	int	size_all;
	int	i;

	i = 0;
	size_all = (size - 1) * ft_strlen(sep);
	while (i < size)
	{
		size_all = size_all + ft_strlen(strs[i]);
		i++;
	}
	return (size_all);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new_str;
	int		size_all;
	int		i;

	i = 0;
	if (size == 0)
	{
		new_str = malloc(sizeof(char));
		new_str[0] = '\0';
		return (new_str);
	}
	size_all = ft_size_all(size, strs, sep);
	new_str = malloc((size_all + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	new_str[0] = '\0';
	while (i < size)
	{
		if (i != 0)
			ft_strcat(new_str, sep);
		ft_strcat(new_str, strs[i]);
		i++;
	}
	return (new_str);
}
/*
#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	printf("./a.out___said___this___is___a___success :\n");
	printf("%s\n",  ft_strjoin(argc, argv, "___"));
}*/
