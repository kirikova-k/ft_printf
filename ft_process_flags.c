/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:12:39 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/18 15:12:44 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_precision(const char *fmt, int i, t_flags *f, va_list *ap)
{
	i++;
	if (fmt[i] == '*')
	{
		f->precision = va_arg(*ap, int);
		i++;
	}
	else
	{
		f->precision = 0;
		while (ft_strchr("0123456789", fmt[i]))
		{
			f->precision = (fmt[i] - '0') + (f->precision * 10);
			i++;
		}
	}
	return (i);
}

void	f_width(t_flags *f, va_list *ap)
{
	f->star = 1;
	f->width = va_arg(*ap, int);
	if (f->width < 0)
	{
		f->minus = 1;
		f->zero = 0;
		f->width = f->width * (-1);
	}
}

void	f_digit(const char *fmt, int i, t_flags *f)
{
	if (f->star == 1)
		f->width = 0;
	if (f->star == 0)
		f->width = f->width * 10 + (fmt[i] - '0');
}
