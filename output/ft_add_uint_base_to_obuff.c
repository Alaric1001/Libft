/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_uint_base_to_obuff.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:33:00 by asenat            #+#    #+#             */
/*   Updated: 2018/09/26 17:43:40 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/obuff.h"

#include "memory/memory.h"
#include "string/string.h"
#include "math/math.h"

void	ft_add_uint_base_to_obuff(uintmax_t nb, const char *format,
									t_obuff *obuff)
{
	char		buf[16];
	size_t		base;
	int			i;

	ft_bzero(&buf, 16);
	base = ft_strlen(format);
	i = ft_get_u_nb_len(nb, base);
	if (!nb)
		buf[0] = '0';
	while (nb)
	{
		buf[i--] = format[nb % base];
		nb /= base;
	}
	ft_add_nstr_to_obuff(buf, 16, obuff);
}
