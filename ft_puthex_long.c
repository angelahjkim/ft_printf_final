/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:49:48 by angkim            #+#    #+#             */
/*   Updated: 2019/10/02 10:19:11 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_long(long n)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (n >= 16)
		ft_puthex_long(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

void	ft_hexlen(long n, int *count)
{
	if (n >= 16)
		ft_hexlen(n / 16, count);
	(*count)++;
}
