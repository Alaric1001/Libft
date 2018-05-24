/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 08:39:47 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:45:30 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "string/string.h"

uintmax_t		get_unb_w_len(t_arg *arg, va_list *args)
{
	unsigned long long ret;

	ret = va_arg(*args, unsigned long long);
	if (arg->e_len == HH)
		return ((unsigned char)ret);
	if (arg->e_len == H)
		return ((unsigned short)ret);
	if (arg->e_len == LL)
		return ((unsigned long long)ret);
	if (arg->e_len == L)
		return ((unsigned long)ret);
	if (arg->e_len == J)
		return ((uintmax_t)ret);
	if (arg->e_len == Z)
		return ((size_t)ret);
	return ((unsigned int)ret);
}

intmax_t		get_nb_w_len(t_arg *arg, va_list *args)
{
	long long ret;

	ret = va_arg(*args, long long);
	if (arg->e_len == HH)
		return ((signed char)ret);
	if (arg->e_len == H)
		return ((short)ret);
	if (arg->e_len == LL)
		return ((long long)ret);
	if (arg->e_len == L)
		return ((long)ret);
	if (arg->e_len == J)
		return ((intmax_t)ret);
	if (arg->e_len == Z)
		return ((ssize_t)ret);
	return ((int)ret);
}

int				getblanks(t_arg *arg, char *to_write, char *zero)
{
	int ret;
	int sub;
	int prec;

	prec = (arg->precision >= 0) ? arg->precision : 0;
	sub = arg->min - (prec + ft_strlen(to_write));
	ret = (arg->min >= 0) ? sub : 0;
	if (arg->sharp_flag)
		ret -= ft_strlen(zero);
	return (ret);
}
