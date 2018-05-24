/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:24:22 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:49:55 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "string/string.h"

int		spec_ptr(t_arg *arg, va_list *args)
{
	unsigned long	ptr;
	char			*to_write;
	int				prec;
	int				ret;

	ptr = (unsigned long)va_arg(*args, void*);
	to_write = itoa_base(ptr, 16, "0123456789abcdef");
	if (ptr == 0 && (arg->precision == 0 || arg->precision == -2))
		ft_strclr(to_write);
	prec = arg->precision;
	arg->precision = (prec >= 0) ? prec - ft_strlen(to_write) : 0;
	arg->sharp_flag = 1;
	arg->min = getblanks(arg, to_write, "0x");
	ret = print_base_nb(to_write, arg, "0x");
	ft_strdel(&to_write);
	return (ret);
}
