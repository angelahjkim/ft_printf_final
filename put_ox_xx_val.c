/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ox_xx_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:35:12 by angkim            #+#    #+#             */
/*   Updated: 2019/10/06 14:07:56 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_prefix_ox_xx(t_format *f)
{
	if (f->spec == 'o' && FLAGS & F_ZERO && FLAGS & F_HASH && f->p)
	{
		PREC--;
		P_ZERO--;
	}
	if (FLAGS & F_HASH)
	{
		if (f->hash_flag == 0)
			ft_putchar('0');
		if (f->spec == 'x')
			ft_putchar('x');
		else if (f->spec == 'X')
			ft_putchar('X');
		(f->spec == 'o') ? (COUNT++) : (COUNT += 2);
	}
	COUNT -= (FLAGS & F_HASH && PREC > LEN && f->spec == 'o') ? 1 : 0;
	while (PREC-- > LEN)
	{
		write(1, "0", 1);
		COUNT++;
		P_ZERO--;
	}
}

void	put_ox_zero(t_format *f)
{
	if (FLAGS & F_HASH)
		put_ox_zero_hash(f);
	else if (f->w_val == -1 && !(f->p))
		write(1, "0", 1);
	else if (f->p && f->p_val != -1)
		return ;
	f->hash_flag = 1;
}

void	put_ox_zero_hash(t_format *f)
{
	if (f->spec == 'x' || f->spec == 'X')
	{
		if (f->p && (PREC == 0 || PREC == 1) && WIDTH > 0)
			write(1, " ", 1);
		else if (PREC == -1 && WIDTH == -1)
			return ;
	}
	else if (f->spec == 'o')
	{
		if (f->p && (PREC == 0 || PREC == 1))
		{
			write(1, "0", 1);
			COUNT++;
		}
		else if (PREC == -1 && WIDTH == -1)
		{
			write(1, "0", 1);
			COUNT++;
		}
	}
}

void	put_ox_value(t_format *f)
{
	if (f->ox_arg == 0 && f->p && (PREC == 0 || PREC == 1))
	{
		if (WIDTH > -1)
			write(1, " ", 1);
		else
			COUNT--;
	}
	else
	{
		if (f->spec == 'o')
			ft_putoctal(f->ox_arg);
		else if (f->spec == 'x' || f->spec == 'X')
		{
			if (f->spec == 'x')
				ft_puthex_l(f->ox_arg);
			else
				ft_puthex_u(f->ox_arg);
		}
	}
}
