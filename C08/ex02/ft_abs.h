/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:08:08 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/31 14:25:32 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(VALUE) (abs(VALUE))

int	abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}
#endif
