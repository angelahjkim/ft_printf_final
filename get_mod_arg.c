/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mod_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:29:47 by angkim            #+#    #+#             */
/*   Updated: 2019/10/06 13:36:51 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_mod_arg_di(t_format *f, va_list args)
{
	if (f->mod == 0)
		f->d_arg = (int)va_arg(args, int);
	else if (f->mod & M_L)
		f->d_arg = (long)va_arg(args, long);
	else if (f->mod & M_LL)
		f->d_arg = va_arg(args, long long);
	else if (f->mod & M_H)
		f->d_arg = (short)va_arg(args, int);
	else if (f->mod & M_HH)
		f->d_arg = (signed char)va_arg(args, int);
}

void	get_mod_arg_u(t_format *f, va_list args)
{
	if (f->mod == 0)
		f->u_arg = (unsigned int)va_arg(args, unsigned int);
	else if (f->mod & M_L)
		f->u_arg = (unsigned long)va_arg(args, unsigned long);
	else if (f->mod & M_LL)
		f->u_arg = (unsigned long long)va_arg(args, unsigned long long);
	else if (f->mod & M_H)
		f->u_arg = (unsigned short)va_arg(args, unsigned int);
	else if (f->mod & M_HH)
		f->u_arg = (unsigned char)va_arg(args, int);
}

void	get_mod_arg_ox_xx(t_format *f, va_list args)
{
	if (f->mod == 0)
		f->ox_arg = (unsigned int)va_arg(args, unsigned int);
	else if (f->mod & M_L)
		f->ox_arg = (unsigned long)va_arg(args, unsigned long);
	else if (f->mod & M_LL)
		f->ox_arg = (unsigned long long)va_arg(args, unsigned long long);
	else if (f->mod & M_H)
		f->ox_arg = (unsigned short)va_arg(args, unsigned int);
	else if (f->mod & M_HH)
		f->ox_arg = (unsigned char)va_arg(args, unsigned int);
}
