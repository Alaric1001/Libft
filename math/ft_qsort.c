/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:40:55 by asenat            #+#    #+#             */
/*   Updated: 2018/10/10 13:11:24 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math/math.h"

#include "memory/memory.h"

#include <stdint.h>

static uint8_t	*get_elem(t_array *arr, int i)
{
	return ((uint8_t*)arr->begin + i * arr->selem);
}

static void		swap(t_array *arr, int index_a, int index_b)
{
	uint8_t tmp[arr->selem];
	uint8_t	*a;
	uint8_t	*b;

	if (index_a == index_b)
		return ;
	a = get_elem(arr, index_a);
	b = get_elem(arr, index_b);
	ft_memcpy(tmp, a, arr->selem);
	ft_memcpy(a, b, arr->selem);
	ft_memcpy(b, tmp, arr->selem);
}

static uint8_t	*get_pivot(t_array *a, int lo, int hi,
					int (*cmp)(void const*, void const*))
{
	int mid;

	mid = (lo + hi) / 2;
	if (cmp(get_elem(a, mid), get_elem(a, lo)) < 0)
		swap(a, lo, mid);
	if (cmp(get_elem(a, hi), get_elem(a, lo)) < 0)
		swap(a, hi, lo);
	if (cmp(get_elem(a, mid), get_elem(a, hi)) < 0)
		swap(a, mid, lo);
	return (get_elem(a, hi));
}

static void		quicksort(t_array *a, int lo, int hi,
					int (*cmp)(void const*, void const*))
{
	uint8_t	*pivot;
	int		i;
	int		j;

	if (lo >= hi)
		return ;
	pivot = get_pivot(a, lo, hi, cmp);
	i = lo;
	j = lo;
	while (j < hi)
	{
		if (cmp(get_elem(a, j), pivot) < 0)
		{
			swap(a, i, j);
			++i;
		}
		++j;
	}
	swap(a, i, hi);
	quicksort(a, lo, i - 1, cmp);
	quicksort(a, i + 1, hi, cmp);
}

void			ft_qsort(t_array *arr,
					int (*cmp)(void const*, void const*))
{
	quicksort(arr, 0, arr->nelems - 1, cmp);
}
