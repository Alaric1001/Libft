/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:36:26 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:48:59 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "string/string.h"

int		print_hex(t_arg *arg, va_list *args, char *hexformat)
{
	char		*to_write;
	int			ret;
	int			prec;
	uintmax_t	raw_nb;

	raw_nb = get_unb_w_len(arg, args);
	to_write = itoa_base(raw_nb, 16, hexformat);
	if (raw_nb == 0 && (arg->precision == 0 || arg->precision == -2))
		ft_strclr(to_write);
	if (raw_nb == 0)
		arg->sharp_flag = 0;
	prec = arg->precision;
	arg->precision = (prec >= 0) ? prec - ft_strlen(to_write) : 0;
	arg->min = getblanks(arg, to_write, "0x");
	ret = print_base_nb(to_write, arg, hexformat + 16);
	ft_strdel(&to_write);
	return (ret);
}

int		spec_up_hex(t_arg *arg, va_list *args)
{
	return (print_hex(arg, args, "0123456789ABCDEF0X"));
}

int		spec_low_hex(t_arg *arg, va_list *args)
{
	return (print_hex(arg, args, "0123456789abcdef0x"));
}
