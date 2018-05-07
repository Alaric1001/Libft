/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:12:54 by asenat            #+#    #+#             */
/*   Updated: 2017/06/15 16:05:56 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <unistd.h>
# include <wchar.h>
# include <stdlib.h>
# include <string.h>


/*
** Output hanling.
*/

/*
** Memory handling.
*/

void				*ft_realloc(void *target, size_t size);

/*
** String Manipulation.
*/




/*
** String utils
*/

char				ft_getmissing_quote(char *str);
char				*ft_strescape(char *s, char *to_escape);
char				**ft_splitfilepath(char *file);
int					ft_star_match(char *str, char *pattern);

/*
** Math
*/

double				ft_pow(double n, int pow);
long int			ft_getnblen(unsigned long long n);

/*
** List handling
*/


#endif
