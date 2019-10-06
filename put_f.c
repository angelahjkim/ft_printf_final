/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:18:32 by angkim            #+#    #+#             */
/*   Updated: 2019/10/06 16:05:17 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_mod_arg_f(t_format *f, va_list args, long double *n, char **s)
{
	uint64_t	whole;
	int			neg;

	neg = 0;
	if (MOD == 'L')
		*n = (long double)va_arg(args, long double);
	else
		*n = (double)va_arg(args, double);
	if (*n < 0)
	{
		*n *= -1;
		neg = 1;
		COUNT++;
	}
	whole = (*n == (double)2147483647) ? 2147483647 : ((uint64_t)*n);
	*n = *n - ((uint64_t)*n);
	if (!f->p)
		PREC = 6;
	LEN = ft_digitcount(whole) + 1 + PREC;
	*s = ft_llutoa(whole, ft_digitcount(whole), LEN);
	return (neg ? 1 : 0);
}

void	put_float(char **format, t_format *f, va_list args)
{
	char		*f_str;
	long double	f_arg;
	int			i;
	int			neg;

	f_str = NULL;
	i = 0;
	neg = get_mod_arg_f(f, args, &f_arg, &f_str);
	P_SPACE = WIDTH - LEN;
	if (!(FLAGS & F_MINUS))
	{
		while (P_SPACE-- > 0)
			write(1, " ", 1);
		COUNT++;
	}
	i += ft_digitcount(ft_atoi(f_str));
	((f->p && !(PREC == -1 || PREC == 0)) || (!f->p)) ? f_str[i++] = '.' : 0;
	while (PREC-- && i < LEN)
	{
		f_arg *= 10;
		f_str[i++] = (uint64_t)f_arg % 10 + 48;
		f_arg = (long double)f_arg - (uint64_t)f_arg;
	}
	f_str[i] = '\0';
	put_float_two(format, f, &f_str, neg);
}

void	put_float_two(char **format, t_format *f, char **f_str, int n)
{
	(n) ? ft_putchar('-') : 0;
	ft_putstr(*f_str);
	COUNT += ft_strlen(*f_str);
	free(*f_str);
	(*format)++;
	reset_struct(f);
}
