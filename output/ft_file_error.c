/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:00:52 by asenat            #+#    #+#             */
/*   Updated: 2018/09/28 16:36:39 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/output.h"
#include "output/obuff.h"

#include <errno.h>

void	ft_file_error(const char *filename, const char *err)
{
	t_obuff buff;

	buff = (t_obuff){.cursor = 0, .fd = 2};
	ft_add_str_to_obuff(filename, &buff);
	ft_add_str_to_obuff(": ", &buff);
	ft_add_str_to_obuff(err, &buff);
	ft_add_str_to_obuff(" [errcode '", &buff);
	ft_add_uint_to_obuff(errno, &buff);
	ft_add_str_to_obuff("']\n", &buff);
	ft_flush_obuff(&buff);
}
