/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:37:38 by angkim            #+#    #+#             */
/*   Updated: 2019/10/02 10:33:17 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putoctal(uint64_t n)
{
	char	*octal_digits;

	octal_digits = "01234567";
	if (n >= 8)
		ft_putoctal(n / 8);
	write(1, &octal_digits[n % 8], 1);
}
