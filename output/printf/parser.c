/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 10:17:19 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:46:36 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "memory/memory.h"

static int		get_specifier(char const *format, t_arg *arg, int cursor)
{
	static int			(*p[])(t_arg*, va_list*) = {spec_string, spec_wstring,
		spec_up_hex, spec_low_hex, spec_oct, spec_up_oct, spec_udec, spec_sdec,
		spec_sdec, spec_up_udec, spec_up_sdec, spec_char, spec_wchar, spec_ptr,
		spec_binary, spec_mod, 0};
	static const char	index[] = {'s', 'S', 'X', 'x', 'o', 'O', 'u', 'd', 'i',
	'U', 'D', 'c', 'C', 'p', 'b', '%', 0};
	int					i;

	i = 0;
	arg->spec_chr = format[cursor];
	while (index[i])
	{
		if (index[i] == format[cursor])
		{
			arg->specifier = p[i];
			return (cursor + 1);
		}
		i++;
	}
	return (cursor);
}

static t_arg	*new_arg(void)
{
	t_arg *arg;

	arg = (struct s_arg*)ft_memalloc(sizeof(struct s_arg));
	arg->precision = -1;
	arg->min = -1;
	arg->specifier = spec_default;
	return (arg);
}

int				parse(char const *format, int *cursor, va_list *args)
{
	t_arg	*arg;
	int		ret;
	int		tmp;

	arg = new_arg();
	ret = 0;
	while (*cursor == (*cursor = get_specifier(format, arg, *cursor)))
	{
		tmp = *cursor;
		*cursor = get_flags(format, arg, *cursor);
		*cursor = get_width(format, arg, *cursor, args);
		*cursor = get_precision(format, arg, *cursor, args);
		*cursor = get_len(format, arg, *cursor);
		if (*cursor == tmp)
			break ;
	}
	ret = arg->specifier(arg, args);
	if (arg->specifier == spec_default && arg->spec_chr)
	{
		(*cursor)++;
		ret++;
	}
	ft_memdel((void**)(&arg));
	return (ret);
}
