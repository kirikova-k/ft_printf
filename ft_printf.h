/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:12:33 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/18 15:22:18 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	type;
	int	width;
	int	minus;
	int	zero;
	int	precision;
	int	star;
	int	sign;
}t_flags;

		/*ft_printf.c*/
int		ft_printf(const char *fmt, ...);
int		ft_parse_input(const char *fmt, va_list *ap);
int		ft_parse_flags(const char *fmt, int i, t_flags *f, va_list *ap);
int		ft_process_types(const char *fmt, int i, t_flags *f, va_list *ap);
t_flags	ft_init_flags(void);

		/*ft_process_flags*/
void	f_width(t_flags *f, va_list *ap);
void	f_digit(const char *fmt, int i, t_flags *f);
int		f_precision(const char *fmt, int i, t_flags *f, va_list *ap);

		/*spec*/
int		spec_c(t_flags *f, va_list *ap);
int		spec_percent(t_flags *f);
int		spec_str(t_flags *f, va_list *ap);
int		spec_int(t_flags *f, va_list *ap);
char	*ft_from_int_to_str(int integer, char *str_int, t_flags *f);
int		ft_flag_minus_int(t_flags *f, char *str_int, int sign);
int		spec_uint(t_flags *f, va_list *ap);
int		ft_flag_minus_uint(t_flags *f, char *str_int);
int		spec_hex(t_flags *f, va_list *ap);
int		ft_flag_minus_hex(t_flags *f, char *str_hex);
int		spec_pointer(t_flags *f, va_list *ap);
void	ft_if_f_zero(t_flags *f);

		/*/src*/
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_ultoa_base(unsigned long n, int base, t_flags *f);
char	*ft_strchr(const char *s, int c);
int		ft_putchar(char c);
int		ft_putstr_n(char *str, int n);
int		ft_putchar_n(char c, int n);
int		ft_nbrlen(unsigned long n, int base);
int		hex_or_dec(unsigned long nb, t_flags *f);

#endif
