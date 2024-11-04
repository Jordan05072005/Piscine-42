/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:49:57 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/22 19:00:44 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i + j] == to_find[j] || to_find[j] == '\0')
			{
				if (to_find[j] == '\0')
					return (&str[i]);
				j++;
			}
		}
		i++;
	}
	return ((void *) 0);
}

/*
int	main(void)
{
	printf("%s",strstr("erat", "a"));
}*/
