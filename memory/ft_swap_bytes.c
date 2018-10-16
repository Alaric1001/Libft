/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bytes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:39:07 by asenat            #+#    #+#             */
/*   Updated: 2018/10/16 16:16:17 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/memory.h"

void		ft_swap_bytes(void *addr, size_t size)
{
	uint8_t *ptr;
	uint8_t tmp;
	size_t	lo;
	size_t hi;

	if (!size)
		return ;
 	ptr = addr;
	lo = 0;
	hi = size - 1;
	while (hi > lo)
	{
		tmp = ptr[lo];
		ptr[lo++]	= ptr[hi];
		ptr[hi--] = tmp;
	}

}

uint32_t	ft_swap_uint32(uint32_t i)
{
	uint32_t ret;

	ret = i;
	ft_swap_bytes(&ret, sizeof(uint32_t));
	return (ret);
}

int32_t		ft_swap_int32(int32_t i)
{
	int32_t ret;

	ret = i;
	ft_swap_bytes(&ret, sizeof(int32_t));
	return (ret);
}

uint64_t	ft_swap_uint64(uint64_t i)
{
	uint64_t ret;

	ret = i;
	ft_swap_bytes(&ret, sizeof(uint64_t));
	return (ret);
}
