/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:17:25 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/18 15:17:27 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_minus_hex(t_flags *f, char *str_hex)
{
	int	len;

	len = 0;
	if (f->minus == 1)
	{
		len += ft_putchar_n('0', f->precision - ft_strlen(str_hex));
		len += ft_putstr_n(str_hex, ft_strlen(str_hex));
		f->width = f->width - len;
		len += ft_putchar_n(' ', f->width);
	}
	if (f->minus == 0)
	{
		f->width = f->width - f->precision;
		len += ft_putchar_n(' ', f->width);
		len += ft_putchar_n('0', f->precision - ft_strlen(str_hex));
		len += ft_putstr_n(str_hex, ft_strlen(str_hex));
	}
	return (len);
}

int	spec_hex(t_flags *f, va_list *ap)
{
	unsigned int	hex;
	int				len;
	char			*str_hex;

	len = 0;
	hex = va_arg(*ap, unsigned int);
	hex = (unsigned int)(4294967295 + hex + 1);
	if (f->precision == 0 && hex == 0)
	{
		f->minus = 0;
		return (len = ft_putchar_n(' ', f->width));
	}
	str_hex = ft_ultoa_base(hex, 16, f);
	if (f->zero == 1 && f->precision < 0)
	{
		f->precision = f->width;
		f->width = 0;
	}
	if ((int)ft_strlen(str_hex) > f->precision)
		f->precision = ft_strlen(str_hex);
	len += ft_flag_minus_hex(f, str_hex);
	free (str_hex);
	return (len);
}
