/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:06:54 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:51:13 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "output/output.h"
#include "string/string.h"

int		put_blanks(t_arg *arg, int authorized, char blank, char *zero)
{
	int i;

	if (!authorized)
		return (0);
	i = 0;
	if (arg->space_flag && zero[0] == '+')
	{
		ft_putchar(' ');
		i++;
	}
	while (i++ < arg->min)
		ft_putchar(blank);
	return (i - 1);
}

int		sub_print_base(char *nb, t_arg *arg, char *zero, int prec)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	if (arg->space_flag && zero[0] == '+' && !arg->sharp_flag && !arg->min)
	{
		ft_putchar(' ');
		ret++;
	}
	arg->space_flag = 0;
	ret += put_blanks(arg, !arg->neg_flag, ' ', 0);
	if (arg->sharp_flag)
		ft_putstr(zero);
	if (prec >= 0)
		while (i++ < prec)
			ft_putchar('0');
	ft_putstr(nb);
	ret += put_blanks(arg, arg->neg_flag, ' ', 0);
	if (i)
		ret += (i - 1);
	return (ret);
}

int		print_base_nb(char *nb, t_arg *arg, char *zero)
{
	int r;

	if (arg->precision > 0)
		r = sub_print_base(nb, arg, zero, arg->precision);
	else
	{
		if (arg->neg_flag)
			r = sub_print_base(nb, arg, zero, -1);
		else
		{
			if (!arg->zero_pad || arg->min <= 0 || arg->precision < 0)
				r = sub_print_base(nb, arg, zero, -1);
			else
			{
				if (arg->sharp_flag)
					ft_putstr(zero);
				r = put_blanks(arg, 1, (arg->prec_reset) ? ' ' : '0', zero);
				ft_putstr(nb);
			}
		}
	}
	if (arg->sharp_flag)
		r += ft_strlen(zero);
	return (ft_strlen(nb) + r);
}
