/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:48:28 by hle-hena          #+#    #+#             */
/*   Updated: 2024/08/07 19:11:58 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, &*str++, 1);
}

int	is_not_num(char *str)
{
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (1);
		str ++;
	}
	return (0);
}

void	*ft_calloc_int(unsigned count, unsigned size)
{
	int				*ptr;
	unsigned int	i;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*ft_strip(char *str)
{
	int		e;
	char	*str_res;

	e = 0;
	while (str[e] != '\n' && str[e])
		e ++;
	str_res = ft_strdup_se(str, 0, e - 1);
	return (str_res);
}

int	is_not_valid(char *str)
{
	int	i;
	int	count;

	if (str == NULL)
		return (0);
	i = 1;
	count = 0;
	while (str[i])
	{
		if (str[i - 1] == '\n' && str[i] == '\n')
			return (0);
		if (str[i] == '\n')
			count ++;
		i ++;
	}
	return (count);
}
