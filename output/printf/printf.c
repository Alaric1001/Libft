/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:16:48 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:58:43 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "output/output.h"
#include "string/string.h"
#include "color/color.h"

static int		print_color(char *open, char *close, int *cursor)
{
	char		*colorcode;
	const char	*color;
	int			i;

	i = -1;
	colorcode = ft_strsub(open, 0, close - open);
	while (colorcode[++i])
		colorcode[i] = ft_toupper(colorcode[i]);
	color = ft_getcolor(colorcode);
	if (!color)
	{
		ft_putchar('{');
		(*cursor)++;
		return (1);
	}
	ft_putstr(color);
	ft_strdel(&colorcode);
	*cursor += close - open + 2;
	return (ft_strlen(color));
}

static int		print_format(char const *format, int *cursor, int limit)
{
	char	*tmp;
	char	*open;
	char	*close;
	int		curs;
	int		wrote;

	tmp = ft_strsub(format, *cursor, limit);
	curs = 0;
	wrote = 0;
	while ((open = ft_strchr(tmp + curs, '{')))
	{
		wrote += open - (tmp + curs);
		curs += ft_putnstr(tmp + curs, open - (tmp + curs));
		if (!(close = ft_strchr(open, '}')))
			break ;
		open++;
		wrote += print_color(open, close, &curs);
	}
	ft_putstr(tmp + curs);
	wrote += ft_strlen(tmp + curs);
	curs += ft_strlen(tmp + curs);
	*cursor += curs;
	ft_strdel(&tmp);
	return (wrote);
}

static int		startparsing(char const *format, va_list *args)
{
	char	*chr;
	int		wrote;
	int		cursor;
	int		width;

	wrote = 0;
	cursor = 0;
	while ((chr = ft_strchr(format + cursor, '%')))
	{
		width = chr - (format + cursor);
		wrote += print_format(format, &cursor, width);
		wrote += parse(++format, &cursor, args);
	}
	wrote += print_format(format, &cursor, ft_strlen(format + cursor));
	return (wrote);
}

int				ft_printf(char const *format, ...)
{
	va_list args;
	int		wrote;

	if (!format[0])
		return (0);
	va_start(args, format);
	wrote = startparsing(format, &args);
	va_end(args);
	return (wrote);
}
