/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:12:13 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:55:42 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "string/string.h"
#include "output/output.h"

int		handle_blanks(char *to_write, int blanks, t_arg *arg)
{
	int i;

	i = 0;
	if (arg->neg_flag)
		ft_putstr(to_write);
	while (i++ < blanks)
		ft_putchar((arg->zero_pad && !arg->neg_flag) ? '0' : ' ');
	if (!arg->neg_flag)
		ft_putstr(to_write);
	return (ft_strlen(to_write) + i - 1);
}

int		spec_string(t_arg *arg, va_list *args)
{
	int		prec;
	char	*to_write;
	int		blanks;
	int		i;

	if (arg->e_len == L)
		return (spec_wstring(arg, args));
	to_write = va_arg(*args, char *);
	if (to_write == NULL)
	{
		ft_strdel(&to_write);
		to_write = "(null)";
	}
	i = 0;
	if (arg->precision == -2)
		arg->precision = 0;
	prec = (arg->precision >= 0) ? arg->precision : ft_strlen(to_write);
	to_write = ft_strsub(to_write, 0, prec);
	blanks = (arg->min >= 0) ? arg->min - ft_strlen(to_write) : 0;
	prec = handle_blanks(to_write, blanks, arg);
	ft_strdel(&to_write);
	return (prec);
}
