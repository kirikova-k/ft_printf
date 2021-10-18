/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:09:37 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/18 15:16:15 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	f;

	f.type = 0;
	f.width = 0;
	f.minus = 0;
	f.zero = 0;
	f.precision = -1;
	f.star = 0;
	f.sign = 0;
	return (f);
}

int	ft_process_types(const char *fmt, int i, t_flags *f, va_list *ap)
{
	int	len;

	len = 0;
	if (fmt[i] == 'c')
		len = (spec_c(f, ap));
	else if (fmt[i] == 's')
		len = spec_str(f, ap);
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		len = spec_int(f, ap);
	else if (fmt[i] == 'u')
		len = spec_uint(f, ap);
	else if (fmt[i] == 'p')
		len = spec_pointer(f, ap);
	else if (fmt[i] == 'x' || fmt[i] == 'X')
		len = spec_hex(f, ap);
	else if (fmt[i] == '%')
		len = spec_percent(f);
	else if (fmt[i] == ' ')
		len = ft_putchar (' ');
	return (len);
}

int	ft_parse_flags(const char *fmt, int i, t_flags *f, va_list *ap)
{
	while (fmt[i] != '\0')
	{
		if (!ft_strchr("cspdiuxX%0123456789*-.", fmt[i]))
			return (i);
		if (fmt[i] == '0' && f->minus == 0 && f->width == 0)
			f->zero = 1;
		if (fmt[i] == '.')
			i = f_precision(fmt, i, f, ap);
		if (fmt[i] == '*')
			f_width(f, ap);
		if (fmt[i] == '-')
		{
			f->minus = 1;
			f->zero = 0;
		}
		if (ft_strchr("0123456789", fmt[i]) != 0)
			f_digit(fmt, i, f);
		if (ft_strchr("cspdiuxX%", fmt[i]) != 0)
		{
			f->type = fmt[i];
			return (i);
		}
		i++;
	}
	return (i);
}

int	parse_input(const char *fmt, va_list *ap)
{
	t_flags	f;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (fmt[i] != '\0' && len >= 0)
	{
		if (fmt[i] == '%' && fmt[i + 1] != '\0')
		{
			i++;
			f = ft_init_flags();
			i = ft_parse_flags(fmt, i, &f, ap);
			if (ft_strchr("cspdiuxX%", fmt[i]) != NULL)
				len = len + ft_process_types(fmt, i, &f, ap);
		}
		else if (fmt[i] != '%')
			len = len + ft_putchar(fmt[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	if (fmt == NULL)
		return (0);
	va_start(ap, fmt);
	len = parse_input(fmt, &ap);
	va_end(ap);
	return (len);
}

/*int	main	(void)*/
/*{*/
/*	ft_printf("35446fdgcf7!@#$ioi");*/
/*	return 0;*/
/*}*/
