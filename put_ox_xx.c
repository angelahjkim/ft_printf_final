/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ox_xx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:26:00 by angkim            #+#    #+#             */
/*   Updated: 2019/10/03 14:42:00 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hex(char **format, t_format *f, va_list args)
{
	uint64_t tmp;

	get_mod_arg_ox_xx(f, args);
	tmp = f->ox_arg;
	while (tmp / 16)
	{
		LEN++;
		tmp /= 16;
	}
	LEN++;
	COUNT += LEN;
	if (f->ox_arg == 0 && f->p == 1 && f->p_val <= 0)
		P_SPACE--;
	put_hex_flags(f);
	(*format)++;
	reset_struct(f);
}

void	put_hex_flags(t_format *f)
{
	if (FLAGS & F_HASH && f->ox_arg && WIDTH > PREC)
		(WIDTH > PREC) ? WIDTH -= 2 : PREC--;
	if (!(FLAGS & F_ZERO) || (FLAGS & F_ZERO && f->p && WIDTH > PREC))
	{
		P_ZERO = PREC - LEN;
		P_SPACE = (WIDTH -= (PREC > LEN) ? PREC : LEN);
	}
	else if (FLAGS & F_ZERO)
	{
		P_ZERO = (WIDTH > PREC) ? (WIDTH - LEN) : (PREC - LEN);
		P_SPACE = 0;
	}
	if (FLAGS & F_HASH && f->ox_arg == 0 && PREC == 0)
		P_SPACE--;
	if (!(FLAGS & F_MINUS))
		put_pad_int(f);
	else if (FLAGS & F_MINUS)
		put_pad_int_minus(f);
}

void	put_octal(char **format, t_format *f, va_list args)
{
	uint64_t tmp;

	get_mod_arg_ox_xx(f, args);
	tmp = f->ox_arg;
	while (tmp / 8)
	{
		LEN++;
		tmp /= 8;
	}
	LEN++;
	COUNT += LEN;
	if (f->ox_arg == 0 && f->p == 1 && f->p_val <= 0)
		P_SPACE--;
	put_octal_flags(f);
	(*format)++;
	reset_struct(f);
}

void	put_octal_flags(t_format *f)
{
	if (!(FLAGS & F_ZERO) || (FLAGS & F_ZERO && f->p))
	{
		P_ZERO = PREC - LEN;
		P_SPACE = (WIDTH -= (PREC > LEN) ? PREC : LEN);
	}
	else if (FLAGS & F_ZERO)
	{
		P_ZERO = (WIDTH > PREC) ? (WIDTH - LEN) : (PREC - LEN);
		P_SPACE = 0;
		if (FLAGS & F_HASH && f->p >= 0 && f->ox_arg)
			P_ZERO--;
	}
	if (P_ZERO > 0 && !(FLAGS & F_ZERO))
		f->hash_flag = 1;
	if (FLAGS & F_HASH && WIDTH >= PREC && f->ox_arg != 0)
		P_SPACE--;
	if (FLAGS & F_HASH && f->ox_arg == 0 && PREC == 0)
		P_SPACE--;
	if (!(FLAGS & F_MINUS))
		put_pad_int(f);
	else if (FLAGS & F_MINUS)
		put_pad_int_minus(f);
}
