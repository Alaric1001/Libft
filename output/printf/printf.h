/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:00:24 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:51:55 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "string/wstring.h"

typedef	struct	s_arg
{
	long	precision;
	long	min;
	int		zero_pad;
	int		neg_flag;
	int		sharp_flag;
	int		space_flag;
	int		plus_flag;
	int		prec_reset;
	char	spec_chr;
	enum
	{
		H = 1,
		HH,
		Z,
		L,
		LL,
		J,
	}		e_len;
	int		(*specifier)(struct s_arg*, va_list*);
}				t_arg;

int				parse(char const *format, int *cursor, va_list *args);
void			my_putwchar(wchar_t c);
void			my_putwstr(wchar_t *s, int n);
int				my_wlen(wchar_t *s);
char			*itoa_base(uintmax_t nbr, int base, char *format);
uintmax_t		get_unb_w_len(t_arg *arg, va_list *args);
intmax_t		get_nb_w_len(t_arg *arg, va_list *args);
int				handle_blanks(char *to_write, int blanks, t_arg *arg);
int				print_base_nb(char *nb, t_arg *arg, char *zero);
int				getblanks(t_arg *arg, char *to_write, char *zero);
int				put_blanks(t_arg *arg, int authorized, char blank, char *zero);

int				spec_string(t_arg *arg, va_list *args);
int				spec_wstring(t_arg *arg, va_list *args);
int				spec_up_hex(t_arg *arg, va_list *args);
int				spec_low_hex(t_arg *arg, va_list *args);
int				spec_oct(t_arg *arg, va_list *args);
int				spec_up_oct(t_arg *arg, va_list *args);
int				spec_udec(t_arg *arg, va_list *args);
int				spec_sdec(t_arg *arg, va_list *args);
int				spec_up_udec(t_arg *arg, va_list *args);
int				spec_up_sdec(t_arg *arg, va_list *args);
int				spec_char(t_arg *arg, va_list *args);
int				spec_wchar(t_arg *arg, va_list *args);
int				spec_ptr(t_arg *arg, va_list *args);
int				spec_binary(t_arg *arg, va_list *args);
int				spec_mod(t_arg *arg, va_list *args);
int				spec_default(t_arg *arg, va_list *args);

int				get_flags(char const *format, t_arg *arg, int cursor);
int				get_width(char const *format, t_arg *arg, int cursor,
				va_list *lst);
int				get_precision(char const *format, t_arg *arg, int cursor,
				va_list *lst);
int				get_len(char const *format, t_arg *arg, int cursor);

#endif
