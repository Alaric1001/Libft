/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:55:47 by asenat            #+#    #+#             */
/*   Updated: 2016/12/16 13:00:20 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrsize(wchar_t *str)
{
	size_t ret;

	ret = 0;
	while (*str)
		ret += ft_wcharsize(*str++);
	return (ret);
}
