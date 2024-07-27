/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:47:19 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/22 18:48:47 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_src;
	unsigned int	size_dest;
	unsigned int	i;

	i = 0;
	size_dest = 0;
	size_src = 0;
	while (dest[size_dest] != '\0')
		size_dest++;
	while (src[size_src] != '\0')
		size_src++;
	if (size_dest < size_src)
		return (size_src + size_dest);
	size = size - size_dest - 1;
	while (src[i] != '\0' && i < size)
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (size_src + size_dest);
}
