/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:12:21 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/18 15:22:48 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	hex_or_dec(unsigned long nb, t_flags *f)
{
	if (nb >= 10)
	{
		if (f->type == 'X')
			return (nb - 10 + 'A');
		if (f->type == 'x' || f->type == 'p')
			return (nb - 10 + 'a');
	}
	return (nb + '0');
}

int	ft_nbrlen(unsigned long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_ultoa_base(unsigned long n, int base, t_flags *f)
{
	int				len_n;
	char			*str;
	unsigned long	tmp;

	tmp = n;
	len_n = ft_nbrlen(n, base);
	str = (char *)malloc(sizeof(char) * (len_n + 1));
	if (!str)
		return (0);
	str[len_n] = '\0';
	while (0 < len_n--)
	{
		tmp = (n % base);
		str[len_n] = hex_or_dec(tmp, f);
		n /= base;
	}
	return (str);
}
