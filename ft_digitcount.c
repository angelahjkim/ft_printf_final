/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:07:42 by angkim            #+#    #+#             */
/*   Updated: 2019/10/02 10:11:28 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_digitcount(long n)
{
	int count;

	count = 0;
	if (n < 0)
		count--;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n / 10)
	{
		count++;
		n /= 10;
	}
	return (count + 1);
}

int		ft_digitcount_u(uint64_t n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n / 10)
	{
		count++;
		n /= 10;
	}
	return (count + 1);
}
