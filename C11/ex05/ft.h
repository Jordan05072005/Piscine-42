/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:46:56 by jguaglio          #+#    #+#             */
/*   Updated: 2024/08/05 18:32:27 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		ft_atoi(char *str);
int		addition(int a, int b);
int		soustraction(int a, int b);
int		multiplication(int a, int b);
int		division(int a, int b);
int		modulo(int a, int b);
void	ft_putnbr(int nbr);
void	doop(int a, int b, char operator, int (*f[])(int, int));
void	doop2(int a, int b, char operator, int (*f[])(int, int));
void	ft_fill(int (*f[])(int, int));
#endif
