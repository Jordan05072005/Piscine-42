/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:08:25 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/23 09:10:39 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	char s1[] = "MyStr";
	char s2[] = "MyTest\nOfSuccess";
	char s3[] = "0123456789abcdef";
	char s4[] = "My\tStr";
	char s5[] = "";
	printf(ft_strlen(s1) == 5 ? "Success\n" : "Fail\n");
	printf(ft_strlen(s2) == 16 ? "Success\n" : "Fail\n");
	printf(ft_strlen(s3) == 16 ? "Success\n" : "Fail\n");
	printf(ft_strlen(s4) == 6 ? "Success\n" : "Fail\n");
	printf(ft_strlen(s5) == 0 ? "Success\n" : "Fail\n");
}*/
