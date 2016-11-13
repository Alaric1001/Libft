/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extractnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:28:25 by asenat            #+#    #+#             */
/*   Updated: 2017/03/06 10:36:26 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_extractnstr(char *str, size_t n)
{
	char	*ret;
	int		i;

	if (!str || !n)
		return (NULL);
	ret = ft_strnew(n);
	i = -1;
	while (++i < n)
		ret[i] = str[i];
	return (ret);
}
