/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:17:03 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/18 15:18:39 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if_f_zero(t_flags *f)
{
	if (f->zero == 1 && f->precision < 0)
	{
		f->precision = f->width;
		f->width = 0;
	}
}

int	ft_flag_minus_pointer(t_flags *f, char *str_pointer)
{
	int	len;

	len = 0;
	if (f->minus == 1)
	{
		f->zero = 0;
		if (f->width < f->precision)
			len = len + ft_putchar_n('0', f->precision - \
		ft_strlen(str_pointer) - 2);
		len = len + ft_putstr_n("0x", 2);
		len = len + ft_putstr_n(str_pointer, f->precision);
		len = len + ft_putchar_n(' ', f->width);
	}
	else if (f->minus == 0)
	{
		if (f->precision > -1)
			len = len + ft_putchar_n(' ', f->width);
		len = len + ft_putchar_n('0', f->precision - \
		ft_strlen(str_pointer) - 2);
		len = len + ft_putstr_n("0x", 2);
		len = len + ft_putstr_n(str_pointer, f->precision);
	}
	return (len);
}

int	spec_pointer(t_flags *f, va_list *ap)
{
	unsigned long	pointer;
	int				len;
	char			*str_pointer;

	len = 0;
	pointer = va_arg(*ap, unsigned long);
	if (f->precision == 0 && pointer == 0)
	{
		if (f->minus == 0)
			len += ft_putchar_n(' ', f->width - 2);
		len += ft_putstr_n("0x", 2);
		if (f->minus == 1)
			len += ft_putchar_n(' ', f->width - 2);
		return (len);
	}
	str_pointer = ft_ultoa_base(pointer, 16, f);
	ft_if_f_zero(f);
	if (f->precision == -1 || f->precision < (int)ft_strlen(str_pointer))
		f->precision = (int)ft_strlen(str_pointer);
	f->width = f->width - f->precision - 2;
	len += ft_flag_minus_pointer(f, str_pointer);
	free (str_pointer);
	return (len);
}
