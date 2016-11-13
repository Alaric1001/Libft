/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:11:45 by asenat            #+#    #+#             */
/*   Updated: 2016/12/01 18:09:23 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *target, size_t size)
{
	char	*res;
	char	*trgt;

	if (!size)
		return (target);
	trgt = (char*)target;
	if (!(res = ft_strnew(ft_strlen(trgt) + size)))
		return (NULL);
	ft_strcpy(res, trgt);
	if (target)
		ft_memdel(&target);
	trgt = NULL;
	return ((void*)res);
}
