/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:07:57 by asenat            #+#    #+#             */
/*   Updated: 2017/03/29 17:20:00 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcappend(char *dst, char c)
{
	dst = ft_realloc(dst, 1);
	dst[ft_strlen(dst)] = c;
	return (dst);
}
