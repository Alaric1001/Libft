/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:21:27 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:45:11 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "string/string.h"
#include "lists/lists.h"

static void		delchain(void *ctt, size_t s)
{
	(void)s;
	ft_strdel((char**)&ctt);
}

char			*itoa_base(uintmax_t nbr, int base, char *format)
{
	int		rest;
	t_list	*l;
	t_list	*tmp;
	char	*res;

	rest = nbr % base;
	nbr /= base;
	l = ft_lstnew(&format[rest], sizeof(char));
	while (nbr > 0)
	{
		rest = nbr % base;
		nbr /= base;
		ft_lstadd(&l, ft_lstnew(&format[rest], sizeof(char)));
	}
	rest = 0;
	res = ft_strnew(ft_lstlen(l));
	while (l)
	{
		res[rest++] = *((char*)(l->content));
		tmp = l->next;
		ft_lstdelone(&l, &delchain);
		l = tmp;
	}
	return (res);
}
