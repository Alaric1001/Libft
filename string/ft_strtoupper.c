/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:11:48 by asenat            #+#    #+#             */
/*   Updated: 2018/10/15 14:14:27 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strtoupper(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		*str = ft_toupper(*str);
		++str;
	}
	return (str);
}
