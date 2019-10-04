/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_diu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:26:00 by angkim            #+#    #+#             */
/*   Updated: 2019/10/03 15:29:57 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_int(char **format, t_format *f, va_list args)
{
	get_mod_arg_di(f, args);
	COUNT += (f->d_arg < 0) ? 1 : 0;
	LEN = ft_digitcount(f->d_arg);
	WIDTH -= (f->d_arg < 0) ? 1 : 0;
	if (FLAGS & F_PLUS || FLAGS & F_SPACE)
	{
		if (f->d_arg >= 0)
			WIDTH--;
	}
	if (!(FLAGS & F_ZERO) || (FLAGS & F_ZERO && f->p))
	{
		P_ZERO = PREC - LEN;
		P_SPACE = (WIDTH -= (PREC > LEN) ? PREC : LEN);
	}
	else if (FLAGS & F_ZERO)
	{
		P_ZERO = (WIDTH > PREC) ? (WIDTH - LEN) : (PREC - LEN);
		P_SPACE = 0;
	}
	(FLAGS & F_MINUS) ? put_pad_int_minus(f) : put_pad_int(f);
	COUNT += ft_digitcount(f->d_arg);
	(*format)++;
	reset_struct(f);
}

void	put_int_value(t_format *f)
{
	if (f->d_arg == 0 && f->p && (PREC == 0 || PREC == 1))
	{
		if (f->spec == 'd' || f->spec == 'i')
		{
			if (WIDTH > -1)
				write(1, " ", 1);
			else
				COUNT--;
		}
		else
		{
			COUNT--;
			return ;
		}
	}
	else
	{
		if ((f->d_arg) + 1 == -9223372036854775807)
			return ;
		(f->spec == 'u') ? ft_putnbr_u(f->u_arg) : ft_putnbr(f->d_arg);
	}
}

void	put_unsigned(char **format, t_format *f, va_list args)
{
	get_mod_arg_u(f, args);
	LEN = ft_digitcount(f->u_arg);
	if (!(FLAGS & F_ZERO) || (FLAGS & F_ZERO && f->p))
	{
		P_ZERO = PREC - LEN;
		P_SPACE = (WIDTH -= (PREC > LEN) ? PREC : LEN);
	}
	else if (FLAGS & F_ZERO)
	{
		P_ZERO = (WIDTH > PREC) ? (WIDTH - LEN) : (PREC - LEN);
		P_SPACE = 0;
	}
	if (!(FLAGS & F_MINUS))
		put_pad_int(f);
	else if (FLAGS & F_MINUS)
		put_pad_int_minus(f);
	COUNT += ft_digitcount_u(f->u_arg);
	(*format)++;
	reset_struct(f);
}
