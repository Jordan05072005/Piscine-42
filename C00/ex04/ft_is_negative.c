/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:59:11 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/17 13:08:46 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n >= 0)
	{
		write(1, "P", 1);
	}
	else
	{
		write(1, "N", 1);
	}
}

/*
int	main(void)
{
	int	n;
	int	n1;
	int	n2;

	n=0;
	n1=7;
	n2=-9;
	ft_is_negative(n);
	ft_is_negative(n1);
	ft_is_negative(n2);

}
*/
