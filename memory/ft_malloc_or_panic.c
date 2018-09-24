/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_or_panic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:35:37 by asenat            #+#    #+#             */
/*   Updated: 2018/09/24 13:41:59 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/memory.h"

#include "output/output.h"

void	*ft_malloc_or_panic(size_t size)
{
	void *ret;

	if (!(ret = malloc(size)))
	{
		ft_putstr_fd("[PANIC] Malloc failed, exiting...\n", 2);
		exit(-1);
	}
	return (ret);
}
