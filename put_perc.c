/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_perc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 15:30:43 by angkim            #+#    #+#             */
/*   Updated: 2019/10/03 16:48:36 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_percent(char **format, t_format *f)
{
	if (**format == '%')
	{
		f->arg_len = 1;
		if (f->flags & F_MINUS)
		{
			ft_putchar('%');
			put_padding(f);
			f->flags -= F_MINUS;
		}
		else
		{
			put_padding(f);
			ft_putchar('%');
		}
		if (WIDTH == -1 && PREC == -1)
			COUNT++;
		f->arg_num = 10;
		(*format)++;
		reset_struct(f);
	}
	else
		f->arg_num = -1;
}
