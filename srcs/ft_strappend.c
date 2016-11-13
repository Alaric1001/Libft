/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:00:23 by asenat            #+#    #+#             */
/*   Updated: 2017/03/29 17:20:15 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *dst, char *src)
{
	if (!src)
		return (dst);
	dst = ft_realloc(dst, ft_strlen(src));
	ft_strcat(dst, src);
	return (dst);
}
