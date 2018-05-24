/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:28:39 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:47:50 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "output/output.h"

int		spec_char(t_arg *arg, va_list *args)
{
	int				blanks;
	unsigned char	c;
	int				i;

	if (arg->e_len == L)
		return (spec_wchar(arg, args));
	i = 0;
	c = (unsigned char)va_arg(*args, int);
	blanks = (arg->min) ? arg->min - 1 : 0;
	if (arg->neg_flag)
		ft_putchar(c);
	while (i++ < blanks)
		ft_putchar((arg->zero_pad && !arg->neg_flag) ? '0' : ' ');
	if (!arg->neg_flag)
		ft_putchar(c);
	return (i);
}
