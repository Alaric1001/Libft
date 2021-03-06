/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:09:40 by asenat            #+#    #+#             */
/*   Updated: 2016/11/10 09:26:22 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists/lists.h"

void	ft_lstadd(t_list **ast, t_list *new)
{
	t_list *tmp;

	tmp = *ast;
	*ast = new;
	(*ast)->next = tmp;
}
