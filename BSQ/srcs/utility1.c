/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:39:15 by hle-hena          #+#    #+#             */
/*   Updated: 2024/08/07 17:11:00 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	*ft_calloc(unsigned count, unsigned size)
{
	void			*ptr;
	unsigned int	i;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

void	*ft_realloc(void *ptr, unsigned int size)
{
	void			*temp;
	unsigned int	i;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		return (malloc(size));
	}
	temp = ft_calloc(size + 1, sizeof(char));
	if (temp == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < size && ((char *)ptr)[i] != '\0')
	{
		((char *)temp)[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (temp);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_strdup_se(char *str, int start, int end)
{
	char	*temp;
	int		i;

	temp = malloc(end - start + 2);
	i = 0;
	while (start <= end)
	{
		temp[i] = str[start];
		i ++;
		start ++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(char *str)
{
	char	**splited;
	int		s;
	int		e;
	int		i;
	int		f;

	s = 0;
	e = -1;
	i = -1;
	f = 0;
	splited = malloc((ft_strlen(str) + 1) * sizeof(char *));
	while (str[++e])
	{
		s = e;
		while (str[e] != '\n' && str[e])
			e ++;
		if (s != e && f)
			splited[++ i] = ft_strdup_se(str, s, e - 1);
		if (!f)
			f = 1;
	}
	splited[i + 1] = NULL;
	return (splited);
}
