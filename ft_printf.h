/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:33:52 by angkim            #+#    #+#             */
/*   Updated: 2019/10/03 17:49:41 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <wchar.h>
# define NUM_CONVS 10
# define COUNT f->count
# define FLAGS f->flags
# define MOD f->mod
# define LEN f->arg_len
# define WIDTH f->w_val
# define PREC f->p_val
# define P_SPACE f->pad_space
# define P_ZERO f->pad_zero

enum	e_flags
{
	F_SPACE = 1 << 0,
	F_PLUS = 1 << 1,
	F_ZERO = 1 << 2,
	F_MINUS = 1 << 3,
	F_HASH = 1 << 4
};

enum	e_mods
{
	M_L = 1 << 0,
	M_LL = 1 << 1,
	M_H = 1 << 2,
	M_HH = 1 << 3,
	M_LD = 1 << 4
};

typedef struct	s_format
{
	char		spec;
	int			mod;
	int			flags;
	intmax_t	d_arg;
	uint64_t	u_arg;
	uint64_t	ox_arg;
	char		*d_str;
	int			arg_num;
	int			arg_len;
	int			count;
	int			w_val;
	int			p;
	int			p_val;
	int			pad_zero;
	int			pad_space;
	int			hash_flag;
}				t_format;

typedef void	t_put_type(char **format, t_format *f, va_list args);

typedef struct	s_arg_table
{
	char		arg;
	t_put_type	*put_arg;
}				t_arg_table;

int				ft_printf(char *format, ...);
int				do_work(char *format, va_list args);
void			ft_newstruct(t_format *f);
void			get_format(char **format, t_format *f);
int				is_flag(char c);
void			get_width(char **format, t_format *f);
void			get_precision(char **format, t_format *f);
void			get_mod(char **format, t_format *f);
void			get_mod_arg_di(t_format *f, va_list args);
void			get_mod_arg_u(t_format *f, va_list args);
void			get_mod_arg_ox_xx(t_format *f, va_list args);
void			reset_struct(t_format *f);
void			put_ordinary(char **format, t_format *f);
void			check_percent(char **format, t_format *f);
void			put_char(char **format, t_format *f, va_list args);
void			put_str(char **format, t_format *f, va_list args);
void			get_str_count_padding(t_format *f, int *to_print);
void			put_pad_str(t_format *f, char *s_arg, int to_print);
void			put_pad_str_minus(t_format *f, char *s_arg, int to_print);
void			put_address(char **format, t_format *f, va_list args);
void			put_add_zero(char **format, t_format *f, long *add_arg);
void			get_add_count_padding(t_format *f, int *to_print);
void			put_pad_add(t_format *f, long *add_str);
void			put_pad_add_minus(t_format *f, long *add_str);
void			put_int(char **format, t_format *f, va_list args);
void			put_pad_int(t_format *f);
void			put_pad_int_minus(t_format *f);
void			put_prefix_int(t_format *f);
void			put_prefix_int_neg(t_format *f);
void			put_int_value (t_format *f);
void			put_unsigned(char **format, t_format *f, va_list args);
void			put_hex(char **format, t_format *f, va_list args);
void			put_ox_zero(t_format *f);
void			put_hex_flags(t_format *f);
void			put_octal(char **format, t_format *f, va_list args);
void			put_octal_flags(t_format *f);
void			put_hash_flag(t_format *f);
void			put_prefix(t_format *f);
void			put_prefix_ox_xx(t_format *f);
void			put_ox_value(t_format *f);
void			put_padding(t_format *f);
void			put_float(char **format, t_format *f, va_list args);
int				ft_atoi(const char *str);
char			*ft_ltoa(long nbr);
char			*ft_llutoa(uint64_t nbr);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_isdigit(int c);
int				ft_digitcount(long n);
int				ft_digitcount_u(uint64_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_puthex_l(uint64_t n);
void			ft_puthex_u(uint64_t n);
void			ft_putoctal(uint64_t n);
void			ft_puthex_long(long n);
void			ft_hexlen(long n, int *count);
void			ft_putnbr(intmax_t n);
void			ft_putnbr_u(uint64_t n);
size_t			ft_strlen(const char *s);
int				ft_iswhitespace(char c);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);

#endif
