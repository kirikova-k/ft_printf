/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c_str_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:17:30 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/18 15:17:33 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spec_c(t_flags *f, va_list *ap)
{
	int		len;
	char	c;

	len = 0;
	c = (char)va_arg(*ap, int);
	f->width--;
	if (f->minus == 1)
	{
		len = len + ft_putchar(c);
		len = len + ft_putchar_n(' ', f->width);
	}
	else if (f->minus == 0)
	{
		len = len + ft_putchar_n(' ', f->width);
		len = len + ft_putchar(c);
	}
	return (len);
}

int	spec_percent(t_flags *f)
{
	int	len;

	len = 0;
	if (f->minus == 1)
		len = ft_putchar('%');
	if (f->zero == 0)
		len = len + ft_putchar_n(' ', f->width - 1);
	if (f->zero == 1)
		len = len + ft_putchar_n('0', f->width - 1);
	if (f->minus == 0)
		len = len + ft_putchar('%');
	return (len);
}

int	spec_str(t_flags *f, va_list *ap)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	if (f->precision <= -1 || f->precision > (int)ft_strlen(str))
		f->precision = (int)ft_strlen(str);
	f->width = f->width - f->precision;
	if (f->minus == 1)
	{
		len = ft_putstr_n(str, f->precision);
		len = len + ft_putchar_n(' ', f->width);
	}
	else if (f->minus == 0)
	{
		len = ft_putchar_n(' ', f->width);
		len = len + ft_putstr_n(str, f->precision);
	}
	return (len);
}
