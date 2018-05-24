/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:40:50 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:48:18 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "string/string.h"

int		spec_udec(t_arg *arg, va_list *args)
{
	char		*to_write;
	int			ret;
	uintmax_t	raw_nb;
	int			prec;

	raw_nb = get_unb_w_len(arg, args);
	to_write = ft_uitoa(raw_nb);
	if (raw_nb == 0 && (arg->precision == 0 || arg->precision == -2))
		ft_strclr(to_write);
	prec = arg->precision;
	arg->precision = (prec >= 0) ? prec - ft_strlen(to_write) : 0;
	arg->min = getblanks(arg, to_write, "");
	ret = print_base_nb(to_write, arg, "");
	ft_strdel(&to_write);
	return (ret);
}

int		spec_sdec(t_arg *arg, va_list *args)
{
	char		*to_write;
	int			ret;
	int			neg;
	intmax_t	raw_nb;
	int			prec;

	raw_nb = get_nb_w_len(arg, args);
	neg = (raw_nb < 0) ? 1 : 0;
	raw_nb = (neg) ? -raw_nb : raw_nb;
	to_write = ft_uitoa(raw_nb);
	if (raw_nb == 0 && (arg->precision == 0 || arg->precision == -2))
		ft_strclr(to_write);
	prec = arg->precision;
	arg->precision = (prec >= 0) ? prec - ft_strlen(to_write) : 0;
	arg->sharp_flag = arg->plus_flag || neg;
	arg->min = getblanks(arg, to_write, "+");
	if (neg)
		ret = print_base_nb(to_write, arg, "-");
	else
		ret = print_base_nb(to_write, arg, "+");
	ft_strdel(&to_write);
	return (ret);
}

int		spec_up_sdec(t_arg *arg, va_list *args)
{
	arg->e_len = L;
	return (spec_sdec(arg, args));
}

int		spec_up_udec(t_arg *arg, va_list *args)
{
	arg->e_len = L;
	return (spec_udec(arg, args));
}
