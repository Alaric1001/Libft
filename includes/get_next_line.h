/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:30:59 by asenat            #+#    #+#             */
/*   Updated: 2017/02/25 14:50:49 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 128

typedef struct	s_content
{
	int		fd;
	char	*rest;
}				t_content;

int				get_next_line(int const fd, char **line);

#endif
