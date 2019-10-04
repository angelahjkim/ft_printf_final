/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:33:33 by angkim            #+#    #+#             */
/*   Updated: 2019/10/02 10:44:36 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_mod(char **format, t_format *f)
{
	if (**format == 'l' && *(*format + 1) != 'l')
		f->mod |= M_L;
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		f->mod |= M_LL;
		(*format)++;
	}
	else if (**format == 'h' && *(*format + 1) != 'h')
		f->mod |= M_H;
	else if (**format == 'h' && *(*format + 1) == 'h')
	{
		f->mod |= M_HH;
		(*format)++;
	}
	else if (**format == 'L')
		f->mod |= M_LD;
	if (f->mod > 0)
		(*format)++;
	f->spec = **format;
}

void	get_precision(char **format, t_format *f)
{
	if (**format == '.')
	{
		f->p = 1;
		(*format)++;
		if (ft_isdigit(**format))
		{
			if (ft_isdigit(**format))
				f->p_val = ft_atoi(*format);
			(*format) += ft_digitcount(f->p_val);
		}
		else
			f->p_val = 0;
	}
	get_mod(format, f);
}

void	get_width(char **format, t_format *f)
{
	if (ft_isdigit(**format))
	{
		f->w_val = ft_atoi(*format);
		(*format) += ft_digitcount(f->w_val);
	}
	get_precision(format, f);
}

int		is_flag(char c)
{
	if (c == ' ' || c == '+' || c == '0' || c == '-' || c == '#')
		return (1);
	return (0);
}

void	get_format(char **format, t_format *f)
{
	while (is_flag(**format))
	{
		if (**format == '+')
			f->flags |= F_PLUS;
		if (**format == ' ')
			f->flags |= F_SPACE;
		if (**format == '-')
			f->flags |= F_MINUS;
		if (**format == '0')
			f->flags |= F_ZERO;
		if (**format == '#')
			f->flags |= F_HASH;
		(*format)++;
	}
	if ((f->flags & F_PLUS) && (f->flags & F_SPACE))
		f->flags -= F_SPACE;
	if ((f->flags & F_MINUS) && (f->flags & F_ZERO))
		f->flags -= F_ZERO;
	get_width(format, f);
}
