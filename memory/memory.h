/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:23:09 by asenat            #+#    #+#             */
/*   Updated: 2018/10/16 16:07:30 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stdlib.h>
# include <stdint.h>

typedef struct	s_array
{
	size_t	nelems;
	size_t	selem;
	void	*begin;
}				t_array;

void			*ft_memalloc(size_t size);
void			*ft_malloc_or_panic(size_t size);
void			ft_memdel(void **ap);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, void const *src, size_t n);
void			*ft_memccpy(void *dest, void const *src, int c, size_t n);
void			*ft_memmove(void *dest, void const *src, size_t n);
void			*ft_memchr(void const *str, int c, size_t n);
int				ft_memcmp(void const *s1, void const *s2, size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_doublearraydel(void ***array);
void			ft_doublearrayndel(void ***array, size_t n);
void			*ft_realloc(void *ptr, size_t ptr_size, size_t new_size);
void			ft_free_array(t_array *array);
void			ft_swap_bytes(void *addr, size_t size);
uint64_t		ft_swap_uint64(uint64_t i);
uint32_t		ft_swap_uint32(uint32_t i);
int32_t			ft_swap_int32(int32_t i);

#endif
