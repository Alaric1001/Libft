/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 13:58:40 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:47:28 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "string/string.h"

int		spec_binary(t_arg *arg, va_list *args)
{
	char		*to_write;
	int			ret;
	int			prec;
	uintmax_t	raw_nb;

	raw_nb = get_unb_w_len(arg, args);
	to_write = itoa_base(raw_nb, 2, "01");
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
