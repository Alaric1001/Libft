/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:43:18 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:48:42 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "output/output.h"

int		spec_default(t_arg *arg, va_list *args)
{
	int i;

	(void)(args);
	i = 0;
	if (arg->neg_flag)
		ft_putchar(arg->spec_chr);
	while (i++ < (arg->min - 1))
		ft_putchar((arg->zero_pad && !arg->neg_flag) ? '0' : ' ');
	if (!arg->neg_flag)
		ft_putchar(arg->spec_chr);
	return (i - 1);
}
