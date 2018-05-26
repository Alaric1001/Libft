/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:08:23 by asenat            #+#    #+#             */
/*   Updated: 2018/05/26 16:34:30 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/obuff.h"

#include "output/output.h"
#include "memory/memory.h"

void	ft_flush_obuff(t_obuff *obuff)
{
	ft_putnstr_fd(obuff->buffer, LIBFT_OBUF_SIZE, obuff->fd);
	ft_bzero(obuff->buffer, LIBFT_OBUF_SIZE);
	obuff->cursor = 0;
}

void	ft_add_str_to_obuff(char const *str, t_obuff *obuff)
{
	int i;

	i = 0;
	while (str[++i])
	{
		if (obuff->cursor == LIBFT_OBUF_SIZE)
			ft_flush_obuff(obuff);
		obuff->buffer[obuff->cursor++] = str[i++];
	}
}

void	ft_add_char_to_obuff(char c, t_obuff *obuff)
{
	if (obuff->cursor == LIBFT_OBUF_SIZE)
		ft_flush_obuff(obuff);
	obuff->buffer[obuff->cursor] = c;
}

void	ft_add_int_to_obuff(int n, t_obuff *obuff)
{
	unsigned int i;

	if (n < 0)
	{
		ft_add_char_to_obuff('-', obuff);
		i = -n;
	}
	else
		i = n;
	if (i >= 10)
	{
		ft_add_int_to_obuff((i / 10), obuff);
		ft_add_int_to_obuff((i % 10), obuff);
	}
	else
		ft_add_char_to_obuff(i + '0', obuff);
}
