/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:58:09 by asenat            #+#    #+#             */
/*   Updated: 2016/12/16 17:52:01 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static long int	n_len(unsigned long long n)
{
	long int len;

	len = 0;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(long long n)
{
	char		*result;
	int			len;
	long long	nb;

	nb = n;
	if (n < 0)
		nb = -n;
	len = n_len(nb) + (n < 0);
	if (!(result = ft_strnew(len + 1)))
		return (NULL);
	if (!nb)
		result[0] = '0';
	while (nb)
	{
		result[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

char			*ft_uitoa(unsigned long long nb)
{
	char		*result;
	int			len;

	len = n_len(nb);
	if (!(result = ft_strnew(len + 1)))
		return (NULL);
	if (!nb)
		result[0] = '0';
	while (nb)
	{
		result[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (result);
}
