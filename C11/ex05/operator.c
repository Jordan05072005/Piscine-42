/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:31:47 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/05 16:34:34 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	addition(int a, int b)
{
	return (a + b);
}

int	soustraction(int a, int b)
{
	return (a - b);
}

int	multiplication(int a, int b)
{
	return (a * b);
}

int	division(int a, int b)
{
	if (b == 0)
		return (-1);
	return (a / b);
}

int	modulo(int a, int b)
{
	if (b == 0)
		return (-1);
	return (a % b);
}
