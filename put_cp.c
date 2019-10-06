/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:26:00 by angkim            #+#    #+#             */
/*   Updated: 2019/10/06 13:46:33 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_address(char **format, t_format *f, va_list args)
{
	long	p;

	p = va_arg(args, long);
	put_add_zero(format, f, &p);
	if (p == 0 && ((PREC >= 0 || WIDTH > 0) || (PREC == -1 && WIDTH == -1)))
		return ;
	ft_hexlen(p, &LEN);
	LEN += 2;
	if (WIDTH < LEN && PREC < LEN)
	{
		ft_putstr("0x");
		if (p == 0 && PREC <= 0)
			(!f->p) ? ft_puthex_long(p) : COUNT--;
		ft_puthex_long(p);
		COUNT += LEN;
	}
	else if (WIDTH > LEN || PREC > LEN)
	{
		if (!(FLAGS & F_MINUS))
			put_pad_add(f, &p);
		else if (FLAGS & F_MINUS)
			put_pad_add_minus(f, &p);
	}
	(*format)++;
	reset_struct(f);
}

void	put_add_zero(char **format, t_format *f, long *p)
{
	if (*p == 0 && ((PREC >= 0 || WIDTH > 0)
		|| (PREC == -1 && WIDTH == -1)))
	{
		LEN = (WIDTH > 0) ? 3 : 1;
		if (f->p && PREC == 0)
			LEN = 0;
		if (!(FLAGS & F_MINUS))
			put_pad_add(f, p);
		else if (FLAGS & F_MINUS)
			put_pad_add_minus(f, p);
		(*format)++;
		reset_struct(f);
	}
}

void	put_pad_add(t_format *f, long *p)
{
	P_ZERO = PREC - LEN;
	P_ZERO += (PREC > LEN && *p != 0) ? 2 : 0;
	P_SPACE = (WIDTH -= (PREC > LEN) ? PREC : LEN);
	while (P_SPACE-- && P_SPACE >= 0)
	{
		write(1, " ", 1);
		COUNT++;
	}
	ft_putstr("0x");
	COUNT += 2;
	while (P_ZERO-- && P_ZERO >= 0)
	{
		write(1, "0", 1);
		COUNT++;
	}
	if (f->p && PREC == 0 && WIDTH == -1)
		return ;
	ft_puthex_long(*p);
	COUNT += LEN;
	COUNT -= (*p != 0 || WIDTH > 0) ? 2 : 0;
}

void	put_pad_add_minus(t_format *f, long *p)
{
	P_SPACE = (WIDTH -= (PREC > LEN) ? PREC : LEN);
	ft_putstr("0x");
	ft_puthex_long(*p);
	COUNT += LEN;
	while (P_SPACE--)
	{
		write(1, " ", 1);
		COUNT++;
	}
}
