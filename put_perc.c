/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_perc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:26:00 by angkim            #+#    #+#             */
/*   Updated: 2019/10/06 14:06:13 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_ordinary(char **format, t_format *f)
{
	ft_putchar(**format);
	f->count++;
	(*format)++;
}

void	put_char(char **format, t_format *f, va_list args)
{
	int c;

	c = va_arg(args, int);
	if (f->w_val > 1)
	{
		if (f->flags & F_MINUS)
			ft_putchar(c);
		while (f->w_val > 1)
		{
			ft_putchar(' ');
			f->w_val--;
			f->count++;
		}
		if (!(f->flags & F_MINUS))
			ft_putchar(c);
	}
	else
		ft_putchar(c);
	f->w_val = 0;
	f->count++;
	(*format)++;
	reset_struct(f);
}

void	check_percent(char **format, t_format *f)
{
	if (**format == '%')
	{
		f->arg_len = 1;
		if (f->flags & F_MINUS && !(WIDTH == -1 && PREC == -1))
		{
			ft_putchar('%');
			COUNT++;
			put_padding(f);
			f->flags -= F_MINUS;
		}
		else
		{
			if (!(WIDTH == -1 && PREC == -1))
				put_padding(f);
			ft_putchar('%');
			COUNT++;
		}
		(*format)++;
		reset_struct(f);
		f->arg_num = 10;
	}
	else
		f->arg_num = -1;
}
