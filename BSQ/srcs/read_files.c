/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:42:39 by hle-hena          #+#    #+#             */
/*   Updated: 2024/08/07 19:25:24 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*ft_rev_str(char *str)
{
	char	tmp;
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i++ - 1] = tmp;
	}
	return (str);
}

t_map	parse_firstline(t_map map, char *str)
{
	str = ft_rev_str(str);
	if (ft_strlen(str) < 4)
		return (null_map(map.map));
	if (str[0] == str[1] || str[1] == str[2] || str[0] == str[2])
		return (null_map(map.map));
	map.full = str[0];
	map.obstacle = str[1];
	map.empty = str[2];
	if (is_not_num(&str[3]))
	{
		return (null_map(map.map));
	}
	map.nb_lines = ft_atoi(ft_rev_str(&str[3]));
	map.len_lines = ft_strlen(map.map[0]);
	return (map);
}

int	get_file_size(char *filename)
{
	int		i;
	char	temp_buff[100000];
	int		fd;
	int		res;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		res = read(fd, temp_buff, 1000);
		if (res == 0)
			break ;
		i += res;
	}
	close(fd);
	return (i);
}

t_map	get_file(char *filename)
{
	t_map	map;
	int		size;
	int		fd;
	char	*buffer;
	char	*temp;

	size = get_file_size(filename);
	if (size == 0)
		return (null_map(map.map));
	fd = open(filename, O_RDONLY);
	buffer = ft_calloc(size + 2, sizeof(char));
	read(fd, buffer, size);
	close (fd);
	if (!is_not_valid(buffer))
		return (free(buffer), null_map(map.map));
	map.map = ft_split(buffer);
	temp = ft_strip(buffer);
	map = parse_firstline(map, temp);
	if (map.nb_lines == -2)
		return (free_strs(map.map), free(temp),
			free(buffer), null_map(map.map));
	free(temp);
	free(buffer);
	return (map);
}
