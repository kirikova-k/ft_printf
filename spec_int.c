/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:17:18 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/18 15:17:21 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_from_int_to_str(int integer, char *str_int, t_flags *f)
{
	if (integer < 0 && integer >= -2147483648)
	{
		if (integer == -2147483648)
			str_int = ft_strdup("2147483648");
		f->sign = 1;
		integer *= -1;
	}
	if (integer != -2147483648)
		str_int = ft_ultoa_base((unsigned int)integer, 10, 0);
	return (str_int);
}

int	ft_flag_minus_int(t_flags *f, char *str_int, int sign)
{
	int	len;

	len = 0;
	if (f->minus == 1)
	{
		if (sign == 1)
			len += ft_putchar('-');
		len += ft_putchar_n('0', f->precision - ft_strlen(str_int));
		len += ft_putstr_n(str_int, ft_strlen(str_int));
		f->width = f->width - len;
		len += ft_putchar_n(' ', f->width);
	}
	if (f->minus == 0)
	{
		f->width = f->width - sign - f->precision;
		len += ft_putchar_n(' ', f->width);
		if (sign == 1)
			len += ft_putchar('-');
		len += ft_putchar_n('0', f->precision - ft_strlen(str_int));
		len += ft_putstr_n(str_int, ft_strlen(str_int));
	}
	return (len);
}

int	spec_int(t_flags *f, va_list *ap)
{
	int		len;
	int		integer;
	char	*str_int;

	len = 0;
	str_int = NULL;
	integer = va_arg(*ap, int);
	if (f->precision == 0 && integer == 0)
	{
		f->minus = 0;
		return (len = ft_putchar_n(' ', f->width));
	}
	str_int = ft_from_int_to_str(integer, str_int, f);
	if (f->zero == 1 && f->precision < 0)
	{
		f->precision = f->width - f->sign;
		f->width = 0;
	}
	if ((int)ft_strlen(str_int) > f->precision)
		f->precision = ft_strlen(str_int);
	free (str_int);
	return (len += ft_flag_minus_int(f, str_int, f->sign));
}
