/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:47:24 by angkim            #+#    #+#             */
/*   Updated: 2019/10/02 11:02:57 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_l(uint64_t n)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (n / 16)
		ft_puthex_l(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

void	ft_puthex_u(uint64_t n)
{
	char	*hex_digits;

	hex_digits = "0123456789ABCDEF";
	if (n / 16)
		ft_puthex_u(n / 16);
	write(1, &hex_digits[n % 16], 1);
}
