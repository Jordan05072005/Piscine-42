/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:26:13 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/30 09:19:13 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	test_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base == NULL || ft_strlen(base) < 2)
		return (0);
	while (i < ft_strlen(base))
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_number;
	long	nb;

	nb = nbr;
	if (test_base(base) == 0)
		return ;
	base_number = ft_strlen(base);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= base_number)
		ft_putnbr_base(nb / base_number, base);
	write(1, &base[nb % base_number], 1);
}

/*
#include <limits.h>
int             main(void)
{
        write(1, "42:", 3);
        ft_putnbr_base(INT_MIN, "0123456789");
        write(1, "\n2a:", 4);
        ft_putnbr_base(42, "0123456789abcdef");
        write(1, "\n-2a:", 5);
        ft_putnbr_base(-42, "0123456789abcdef");
        write(1, "\n:", 2);
        ft_putnbr_base(42, "");
        write(1, "\n:", 2);
        ft_putnbr_base(42, "0");
        write(1, "\n:", 2);
        ft_putnbr_base(42, "0123456+789abcdef");
        write(1, "\n:", 2);
        ft_putnbr_base(42, "\t0123456\t789abcdef");
        write(1, "\n:", 2);
        ft_putnbr_base(42, "\t0123456789abcde0");
        write(1, "\n:", 2);
	char * test = NULL;
        ft_putnbr_base(42, test);

}*/
