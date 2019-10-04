/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:07:23 by angkim            #+#    #+#             */
/*   Updated: 2019/10/03 15:24:57 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(intmax_t n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n / 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putnbr_u(uint64_t n)
{
	if (n / 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
