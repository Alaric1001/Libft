/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi-colors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:44:19 by asenat            #+#    #+#             */
/*   Updated: 2018/05/07 18:03:19 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H

# define COLOR_NB	11
# define RESET		"\033[0m"
# define HIGHLIGHT	"\033[1m"
# define UNDERLINE	"\033[4m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

typedef struct	s_conv {
	char	*str;
	char	*color;
}				t_conv;

char const		*ft_getcolor(char const *code);

#endif
