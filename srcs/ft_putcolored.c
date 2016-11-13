/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolored.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:50:19 by asenat            #+#    #+#             */
/*   Updated: 2017/02/12 16:07:11 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_colors.h"

int		ft_putcolored(char *s, char *code, int fd)
{
	char	*color;

	if (!s || !code)
		return (-1);
	color = ft_getcolor(code);
	if (!color)
		return (0);
	ft_putstr_fd(color, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(ft_getcolor("RESET"), fd);
	return (1);
}
