/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char_str_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:11:55 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/18 15:12:00 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_n(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && n > 0)
	{
		write(1, &str[i], 1);
		i++;
		n--;
	}
	return (i);
}

int	ft_putchar_n(char c, int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len += ft_putchar(c);
		n--;
	}
	return (len);
}
