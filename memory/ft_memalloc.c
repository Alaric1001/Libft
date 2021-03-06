/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:52:28 by asenat            #+#    #+#             */
/*   Updated: 2018/09/24 13:43:02 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/memory.h"

void	*ft_memalloc(size_t size)
{
	void *result;

	result = ft_malloc_or_panic(size);
	ft_memset(result, 0, size);
	return (result);
}
