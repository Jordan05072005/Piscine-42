/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:09:32 by hle-hena          #+#    #+#             */
/*   Updated: 2024/08/07 19:31:30 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_map	parse(t_map map, char *str)
{
	str = ft_rev_str(str);
	if (ft_strlen(str) < 4)
		return (null_map(NULL));
	map.full = str[0];
	map.obstacle = str[1];
	map.empty = str[2];
	if (is_not_num(&str[3]) || str[0] == str[1] || str[1] == str[2]
		|| str[0] == str[2])
		return (null_map(NULL));
	map.nb_lines = ft_atoi(ft_rev_str(&str[3]));
	return (map);
}

int	count_lines(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '\n' && (str[i + 1] == '\n'))
			count++;
		i++;
	}
	return (count);
}

char	*read_stdin(void)
{
	int		size;
	char	buff[1000];
	t_map	map;
	char	*str;
	char	*temp;

	str = ft_calloc(1, sizeof(char));
	while (1)
	{
		size = read(0, buff, 999);
		buff[size] = '\0';
		if (str[0] == '\0')
		{
			temp = ft_strip(buff);
			map = parse(map, temp);
			free(temp);
			if (map.nb_lines <= 0)
				return (free(str), NULL);
		}
		str = ft_realloc(str, ft_strlen(str) + size);
		ft_strcat(str, buff);
		if (count_lines(str) >= map.nb_lines + 1 || buff[0] == '\n' 
			|| buff == 0)
			return (str);
	}
	return (str);
}

t_map	get_stdin(void)
{
	t_map	map_struct;
	char	*str;
	char	*temp;

	str = read_stdin();
	if (str == NULL || !(is_not_valid(str) > 0))
	{
		free(str);
		return (null_map(NULL));
	}
	map_struct.map = ft_split(str);
	temp = ft_strip(str);
	map_struct = parse(map_struct, temp);
	free(temp);
	free(str);
	map_struct.len_lines = ft_strlen(map_struct.map[0]);
	return (map_struct);
}
