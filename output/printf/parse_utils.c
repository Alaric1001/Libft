/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:36:44 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:46:18 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "string/string.h"

int			get_flags(char const *format, t_arg *arg, int cursor)
{
	while (format[cursor])
	{
		if (format[cursor] == '#')
			arg->sharp_flag = 1;
		else if (format[cursor] == '-')
			arg->neg_flag = 1;
		else if (format[cursor] == '0')
			arg->zero_pad = 1;
		else if (format[cursor] == '+')
			arg->plus_flag = 1;
		else if (format[cursor] == ' ')
			arg->space_flag = 1;
		else
			return (cursor);
		cursor++;
	}
	return (cursor);
}

int			get_width(char const *format, t_arg *arg, int cursor, va_list *lst)
{
	int tmp;
	int width;

	tmp = cursor;
	if (format[cursor] == '*')
	{
		tmp = va_arg(*lst, int);
		arg->min = (tmp < 0) ? -tmp : tmp;
		if (tmp < 0)
			arg->neg_flag = 1;
		return (++cursor);
	}
	width = ft_atoi(format + cursor);
	while (ft_isdigit(format[cursor]))
		cursor++;
	if (width > 0 && tmp != cursor)
		arg->min = width;
	return (cursor);
}

int			get_precision(char const *f, t_arg *arg, int cursor, va_list *lst)
{
	if (f[cursor] != '.')
		return (cursor);
	cursor++;
	if (f[cursor] == '*')
	{
		arg->precision = va_arg(*lst, int);
		return (++cursor);
	}
	if (ft_isdigit(f[cursor]))
		arg->precision = ft_atoi(f + cursor);
	else
	{
		if (arg->precision >= 0)
			arg->prec_reset = 1;
		arg->precision = -2;
	}
	while (ft_isdigit(f[cursor]))
		cursor++;
	return (cursor);
}

static int	handle_dbl_len(char const *format, t_arg *arg, int cursor)
{
	if (format[cursor] == 'h')
	{
		arg->e_len = (arg->e_len < H) ? H : arg->e_len;
		cursor++;
		if (format[cursor] == 'h')
		{
			arg->e_len = (arg->e_len < HH) ? HH : arg->e_len;
			cursor++;
		}
	}
	else if (format[cursor] == 'l')
	{
		arg->e_len = (arg->e_len < L) ? L : arg->e_len;
		cursor++;
		if (format[cursor] == 'l')
		{
			arg->e_len = (arg->e_len < LL) ? LL : arg->e_len;
			cursor++;
		}
	}
	return (cursor);
}

int			get_len(char const *format, t_arg *arg, int cursor)
{
	int ret;

	ret = handle_dbl_len(format, arg, cursor);
	if (format[cursor] == 'j')
	{
		arg->e_len = (arg->e_len < J) ? J : arg->e_len;
		ret++;
	}
	else if (format[cursor] == 'z')
	{
		arg->e_len = (arg->e_len < Z) ? Z : arg->e_len;
		ret++;
	}
	return (ret);
}
