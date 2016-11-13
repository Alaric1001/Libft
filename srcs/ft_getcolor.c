/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:49:42 by asenat            #+#    #+#             */
/*   Updated: 2016/12/19 08:59:21 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_colors.h"

char	*ft_getcolor(char *code)
{
	static const t_conv		conv[] = {
		{"RESET", RESET},
		{"HIGHLIGHT", HIGHLIGHT},
		{"UNDERLINE", UNDERLINE},
		{"BLACK", BLACK},
		{"RED", RED},
		{"GREEN", GREEN},
		{"YELLOW", YELLOW},
		{"BLUE", BLUE},
		{"PURPLE", PURPLE},
		{"CYAN", CYAN},
		{"WHITE", WHITE}
	};
	int						i;

	i = -1;
	while (++i < COLOR_NB)
		if (ft_strequ(conv[i].str, code))
			return (conv[i].color);
	return (NULL);
}
