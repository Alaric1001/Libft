/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obuff.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:21:07 by asenat            #+#    #+#             */
/*   Updated: 2018/05/26 16:25:17 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBUFF_H
# define FT_OBUFF_H

# include "stdlib.h"

# define LIBFT_OBUF_SIZE 75ul

typedef struct	s_obuff
{
	char	buffer[LIBFT_OBUF_SIZE];
	size_t	cursor;
	int		fd;
}				t_obuff;

void			ft_add_char_to_obuff(char s, t_obuff *obuff);
void			ft_add_str_to_obuff(char const *s, t_obuff *obuff);
void			ft_add_int_to_obuff(int nbr, t_obuff *obuff);
void			ft_flush_obuff(t_obuff *obuff);

#endif
