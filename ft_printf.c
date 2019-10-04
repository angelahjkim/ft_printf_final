/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:49:26 by angkim            #+#    #+#             */
/*   Updated: 2019/10/03 16:14:36 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg_table	g_checkarg[] = {
	{'c', &put_char},
	{'s', &put_str},
	{'p', &put_address},
	{'d', &put_int},
	{'i', &put_int},
	{'u', &put_unsigned},
	{'o', &put_octal},
	{'x', &put_hex},
	{'X', &put_hex},
	{'f', &put_float},
};

int		ft_printf(char *format, ...)
{
	va_list	args;
	int		done;

	va_start(args, format);
	done = do_work(format, args);
	va_end(args);
	return (done);
}

int		do_work(char *format, va_list args)
{
	t_format	*f;
	int			printed_chars;

	f = (t_format *)ft_memalloc(sizeof(t_format));
	ft_newstruct(f);
	while (*format)
	{
		if (*format == '%' && *(format++))
		{
			get_format(&format, f);
			check_percent(&format, f);
			while (++f->arg_num < NUM_CONVS)
				if (*format == g_checkarg[f->arg_num].arg)
				{
					g_checkarg[f->arg_num].put_arg(&format, f, args);
					break ;
				}
		}
		else if (*format != '%')
			put_ordinary(&format, f);
	}
	printed_chars = f->count;
	free(f);
	return (printed_chars);
}

void	ft_newstruct(t_format *f)
{
	f->mod = 0;
	f->flags = 0;
	f->count = 0;
	f->arg_num = -1;
	f->w_val = -1;
	f->p = 0;
	f->p_val = -1;
	f->arg_len = 0;
	f->d_str = NULL;
	f->pad_space = -1;
	f->pad_zero = -1;
	f->hash_flag = 0;
}
