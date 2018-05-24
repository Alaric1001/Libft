/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_wstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:17:30 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 18:50:29 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "output/output.h"

static	int	write_wstring(wchar_t *to_write, int prec, int blanks, t_arg *arg)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	if (arg->neg_flag)
		ret = ft_putnbyteswstr(to_write, prec);
	while (i++ < blanks)
		ft_putchar((arg->zero_pad && !arg->neg_flag) ? '0' : ' ');
	if (!arg->neg_flag)
		ret = ft_putnbyteswstr(to_write, prec);
	return (ret + i - 1);
}

static int	getwblanks(wchar_t *str, int prec, t_arg *arg)
{
	int		ret;
	wchar_t	*tmp;
	int		size;

	tmp = str;
	ret = 0;
	while (prec > 0 && *tmp)
	{
		size = ft_wcharsize(*tmp++);
		if (prec < size)
			return (arg->min - ret);
		prec -= size;
		ret += size;
	}
	return (arg->min - ret);
}

int			spec_wstring(t_arg *arg, va_list *args)
{
	int		ret;
	wchar_t	*to_write;
	int		prec;
	int		blanks;
	size_t	size;

	to_write = va_arg(*args, wchar_t *);
	if (to_write == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ret = 0;
	if (arg->precision == -2)
		arg->precision = 0;
	size = ft_wstrsize(to_write);
	prec = (arg->precision >= 0) ? arg->precision : size;
	blanks = (arg->min >= 0) ? getwblanks(to_write, prec, arg) : 0;
	ret = write_wstring(to_write, prec, blanks, arg);
	return (ret);
}

int			spec_wchar(t_arg *arg, va_list *args)
{
	int		i;
	wchar_t	to_write;
	int		blanks;
	size_t	wsize;

	i = 0;
	to_write = (wchar_t)va_arg(*args, wint_t);
	wsize = ft_wcharsize(to_write);
	blanks = (arg->min >= 0) ? arg->min - wsize : 0;
	if (arg->neg_flag)
		ft_putwchar(to_write, wsize);
	while (i++ < blanks)
		ft_putchar((arg->zero_pad && !arg->neg_flag) ? '0' : ' ');
	if (!arg->neg_flag)
		ft_putwchar(to_write, wsize);
	return ((i - 1) + wsize);
}
