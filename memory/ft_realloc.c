/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:09:01 by asenat            #+#    #+#             */
/*   Updated: 2018/09/26 10:17:30 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/memory.h"

void	*ft_realloc(void *ptr, size_t ptr_size, size_t new_size)
{
	void *ret;

	ret = ft_memalloc(new_size);
	if (new_size < ptr_size)
		ptr_size = new_size;
	ft_memcpy(ret, ptr, ptr_size);
	free(ptr);
	return (ret);
}
