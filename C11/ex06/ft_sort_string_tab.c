/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:15:39 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/05 18:10:19 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	swap(char **str, int a, int b)
{
	char	*temp;

	temp = str[a];
	str[a] = str[b];
	str[b] = temp;
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

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				swap(tab, i, j);
			j++;
		}
		i++;
	}
}
/*
#include <stdio.h>

int main(int ac, char **av)
{
	int	i;

	i = 0;
	(void)ac;
	ft_sort_string_tab(av);
	while (i < ac)
	{
		printf("%s\n", av[i]);
		i++;
	}
}*/
