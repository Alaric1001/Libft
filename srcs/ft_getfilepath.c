/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfilepath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:27:02 by asenat            #+#    #+#             */
/*   Updated: 2017/06/08 13:33:47 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_splitfilepath(char *file)
{
	char *tmp;

	tmp = file;
	while ((tmp = ft_strchr(tmp, '/')))
		tmp += 1;
	tmp -= 1;
	return (ft_strsub(file, 0, file - tmp));
}
