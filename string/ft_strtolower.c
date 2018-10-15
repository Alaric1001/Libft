/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:15:39 by asenat            #+#    #+#             */
/*   Updated: 2018/10/15 14:16:00 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strtolower(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		*str = ft_tolower(*str);
		++str;
	}
	return (str);
}
