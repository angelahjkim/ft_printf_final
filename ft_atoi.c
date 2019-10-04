/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:54:05 by angkim            #+#    #+#             */
/*   Updated: 2019/08/13 14:14:31 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Converts the initial portion of the string pointed to by str to int
** representation.
*/

int		ft_atoi(const char *str)
{
	int i;
	int num;
	int sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit((char)str[i]))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}
