/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:55:15 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:49:19 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		spec_mod(t_arg *arg, va_list *args)
{
	int blanks;

	(void)args;
	blanks = (arg->min) ? arg->min - 1 : 0;
	return (handle_blanks("%", blanks, arg));
}
