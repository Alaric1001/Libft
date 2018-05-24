/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:05:47 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:49:35 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "string/string.h"

int		spec_oct(t_arg *arg, va_list *args)
{
	char		*to_write;
	int			ret;
	int			prec;
	uintmax_t	raw_nb;

	raw_nb = get_unb_w_len(arg, args);
	to_write = itoa_base(raw_nb, 8, "012345678");
	if (raw_nb == 0 && (arg->precision == 0 || arg->precision == -2))
		ft_strclr(to_write);
	if (raw_nb == 0 && (arg->precision == -1 || arg->precision > 0))
		arg->sharp_flag = 0;
	prec = (arg->sharp_flag) ? arg->precision - 1 : arg->precision;
	arg->precision = (prec >= 0) ? prec - ft_strlen(to_write) : 0;
	arg->min = getblanks(arg, to_write, "0");
	ret = print_base_nb(to_write, arg, "0");
	ft_strdel(&to_write);
	return (ret);
}

int		spec_up_oct(t_arg *arg, va_list *args)
{
	arg->e_len = L;
	return (spec_oct(arg, args));
}
