/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnblen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:16:11 by asenat            #+#    #+#             */
/*   Updated: 2018/09/26 17:30:05 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math/math.h"

size_t	ft_get_u_nb_len(uintmax_t n, uint16_t base)
{
	size_t len;

	if (!base)
		return (0);
	len = 0;
	while (n /= base)
		len++;
	return (len);
}
