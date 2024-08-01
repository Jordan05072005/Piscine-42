/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:30:49 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/01 10:17:33 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	i = 0;
	tab = malloc((ac + 1) * sizeof(t_stock_str));
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = malloc((ft_strlen(av[i]) + 1) * sizeof(char));
		if (tab[i].str == NULL)
			return (NULL);
		ft_strcpy(tab[i].str, av[i]);
		tab[i].copy = malloc((ft_strlen(av[i]) + 1) * sizeof(char));
		if (tab[i].str == NULL)
			return (NULL);
		ft_strcpy(tab[i].copy, av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
/*
int	main(int argc, char ** argv)
{
	ft_show_tab(ft_strs_to_tab(argc, argv));
}*/
