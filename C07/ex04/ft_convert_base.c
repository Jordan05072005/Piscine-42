/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:26:13 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/31 13:07:31 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	test_base(char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_malloc_str(char **str, char *base, int nbr)
{
	int		i;
	int		base_number;
	long	sum;
	long	nb;

	i = 0;
	nb = nbr;
	if (nb < 0)
		nb = -nb;
	sum = 1;
	base_number = ft_strlen(base);
	while (sum < nb)
	{
		sum = sum * base_number;
		i++;
	}
	*str = malloc((i + 1) * sizeof(char));
}

void	ft_putnbr_base(int nbr, char *base, char *nbr_final, int indice)
{
	int		base_number;
	long	nb;

	nb = nbr;
	base_number = ft_strlen(base);
	if (nb < 0)
	{
		nbr_final[indice] = '-';
		indice++;
		nb = -nb;
	}
	if (nb >= base_number)
	{
		nbr_final[indice] = base[nb % base_number];
		indice++;
		ft_putnbr_base(nb / base_number, base, nbr_final, indice);
		return ;
	}
	nbr_final[indice] = base[nb];
}

void	ft_reverse_str(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nbr_decimal;
	char	*nbr_final;

	if (test_base(base_to) == 0 || test_base(base_from) == 0)
		return (NULL);
	nbr_decimal = ft_atoi_base(nbr, base_from);
	ft_malloc_str(&nbr_final, base_to, nbr_decimal);
	ft_putnbr_base(nbr_decimal, base_to, nbr_final, 0);
	if (nbr_decimal < 0)
		ft_reverse_str(&nbr_final[1]);
	else
		ft_reverse_str(nbr_final);
	return (nbr_final);
}
/*
#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	printf("42:%s\n", ft_convert_base("-2147483648",
			       	"0123456789", "0123456789"));
	printf("-2a:%s\n", ft_convert_base("-42", "0123456789",
			       	"0123456789abcdef"));
}*/
