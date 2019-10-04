/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:18:32 by angkim            #+#    #+#             */
/*   Updated: 2019/10/03 15:23:06 by angkim           ###   ########.fr       */
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
	whole = ((uint64_t)*n);
	*n = *n - ((uint64_t)*n);
	if (!f->p)
		PREC = 6;
	LEN = ft_digitcount(whole) + 1 + PREC;
	*s = ft_memalloc(sizeof(char) * LEN + 1);
	*s = ft_llutoa(whole);
	return (neg ? 1 : 0);
}

void	put_float_pad(t_format *f, char **f_str, long double *f_arg, int *i)
{
	long double	cast;

	cast = 0;
	while (PREC-- > 0)
	{
		*f_arg *= 10;
		cast = (*f_arg > 0) ? 0.5 : -0.5;
		*f_str[(*i)++] = ((uint64_t)(*f_arg + cast) % 10) + 48;
		*f_arg = *f_arg - (uint64_t)*f_arg;
	}
	*(f_str)[*i] = '\0';
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
	if ((f->p && !(PREC == -1 || PREC == 0)) || (!f->p))
		f_str[i++] = '.';
	put_float_pad(f, &f_str, &f_arg, &i);
	(neg) ? ft_putchar('-') : 0;
	ft_putstr(f_str);
	COUNT += ft_strlen(f_str);
	free(f_str);
	(*format)++;
	reset_struct(f);
}
