/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 00:32:26 by angkim            #+#    #+#             */
/*   Updated: 2019/10/02 10:47:35 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_str(char **format, t_format *f, va_list args)
{
	char	*s_arg;
	int		to_print;
	int		str_null;

	s_arg = (char *)va_arg(args, char *);
	to_print = 0;
	str_null = 0;
	if (s_arg == NULL)
	{
		s_arg = ft_strdup("(null)");
		str_null = 1;
	}
	LEN = ft_strlen((char *)s_arg);
	get_str_count_padding(f, &to_print);
	if (WIDTH > LEN && LEN > PREC && PREC > WIDTH && PREC != -1 && WIDTH != -1)
		ft_putstr(s_arg);
	else if (FLAGS & F_MINUS)
		put_pad_str_minus(f, s_arg, to_print);
	else if (!(FLAGS & F_MINUS))
		put_pad_str(f, s_arg, to_print);
	(str_null) ? free(s_arg) : 0;
	(*format)++;
	reset_struct(f);
}

void	get_str_count_padding(t_format *f, int *to_print)
{
	if (f->p)
		*to_print += (PREC <= LEN) ? PREC : LEN;
	else if (f->p && PREC == -1)
		*to_print = 0;
	else if (!f->p)
		*to_print = LEN;
	if (f->p && WIDTH != -1)
	{
		P_SPACE = (PREC >= LEN) ? WIDTH - *to_print : WIDTH - PREC;
		if (PREC == -1)
			P_SPACE--;
	}
	else if (f->p && WIDTH == -1)
		P_SPACE = 0;
	else if (!f->p)
		P_SPACE = WIDTH - *to_print;
}

void	put_pad_str(t_format *f, char *s_arg, int to_print)
{
	int i;

	i = 0;
	while (P_SPACE-- > 0)
	{
		write(1, " ", 1);
		COUNT++;
	}
	while (to_print-- > 0 && s_arg[i])
	{
		write(1, &s_arg[i++], 1);
		COUNT++;
	}
}

void	put_pad_str_minus(t_format *f, char *s_arg, int to_print)
{
	int i;

	i = 0;
	while (to_print-- > 0 && s_arg[i])
	{
		write(1, &s_arg[i++], 1);
		COUNT++;
	}
	while (P_SPACE-- > 0)
	{
		write(1, " ", 1);
		COUNT++;
	}
}
