/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfilepath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:27:02 by asenat            #+#    #+#             */
/*   Updated: 2017/06/08 13:31:24 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_splitfilepath(char *file)
{
	char *tmp;
	char **ret;

	ret = ft_memalloc(sizeof(char*) * 3);
	if (!strchr(file, '/'))
	{
		ret[1] = ft_strdup(file);
		return (ret);
	}
	tmp = file;
	while (ft_strchr(file, '/'))
		file = ft_strchr(file, '/') + 1;
	file--;
	ret[0] = ft_strsub(tmp, 0, (file - tmp) + 1);
	ret[1] = ft_strdup(file + 1);
	return (ret);
}
