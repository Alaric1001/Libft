/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:25:14 by asenat            #+#    #+#             */
/*   Updated: 2018/10/10 13:11:42 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include <stdlib.h>
# include <stdint.h>

size_t		ft_get_u_nb_len(uintmax_t n, uint16_t base);
size_t		safe_u_mult(size_t a, size_t b, uint8_t *overflow);
intmax_t	safe_mult(intmax_t a, intmax_t b, uint8_t *overflow);

typedef struct s_array	t_array;
void		ft_qsort(t_array *arr, int (*cmp)(void const*, void const*));

#endif
