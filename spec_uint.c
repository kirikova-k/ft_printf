/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:16:54 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/18 15:16:56 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_minus_uint(t_flags *f, char *str_uint)
{
	int	len;

	len = 0;
	if (f->minus == 1)
	{
		len += ft_putchar_n('0', f->precision - ft_strlen(str_uint));
		len += ft_putstr_n(str_uint, ft_strlen(str_uint));
		f->width = f->width - len;
		len += ft_putchar_n(' ', f->width);
	}
	if (f->minus == 0)
	{
		f->width = f->width - f->precision;
		len += ft_putchar_n(' ', f->width);
		len += ft_putchar_n('0', f->precision - ft_strlen(str_uint));
		len += ft_putstr_n(str_uint, ft_strlen(str_uint));
	}
	return (len);
}

int	spec_uint(t_flags *f, va_list *ap)
{
	int					len;
	unsigned int		uinteger;
	char				*str_uint;

	len = 0;
	uinteger = va_arg(*ap, unsigned int);
	uinteger = (unsigned int)(4294967295 + uinteger + 1);
	if (f->precision == 0 && uinteger == 0)
	{
		f->minus = 0;
		return (len = ft_putchar_n(' ', f->width));
	}
	str_uint = ft_ultoa_base(uinteger, 10, 0);
	if (f->zero == 1 && f->precision < 0)
	{
		f->precision = f->width;
		f->width = 0;
	}
	if ((int)ft_strlen(str_uint) > f->precision)
		f->precision = ft_strlen(str_uint);
	len += ft_flag_minus_uint(f, str_uint);
	free (str_uint);
	return (len);
}
