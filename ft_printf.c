/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:15:25 by hfanzaou          #+#    #+#             */
/*   Updated: 2021/11/26 22:05:33 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_part(const char *str, va_list a, int *l)
{
	if (*str == 'c')
	{
		ft_putchar_fd((char)va_arg(a, int), 1);
		*l += 1;
	}
	else if (*str == 's')
		ft_putstr(va_arg(a, char *), l);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(a, int), l);
	else if (*str == 'u')
		ft_putunbr(va_arg(a, unsigned int), l);
	else if (*str == 'x')
		ft_putnbr_base(va_arg(a, unsigned int), "0123456789abcdef", l);
	else if (*str == 'X')
		ft_putnbr_base(va_arg(a, unsigned int), "0123456789ABCDEF", l);
	else if (*str == 'p')
	{
		ft_putstr("0x", l);
		ft_putnbr_base(va_arg(a, unsigned long int), "0123456789abcdef", l);
	}
	else if (*str == '%')
	{
		*l += 1;
		ft_putchar_fd('%', 1);
	}
}

int ft_printf(const char *str, ...)
{
	va_list a;
	int i;

	va_start(a, str);
	i = 0;
	while (*str && str)
	{
		if (*str == '%')
		{
			str++;
			ft_print_part(str, a, &i);
		}
		else 
		{
			i++;
			ft_putchar_fd(*str, 1);
		}
		str++;
	}
	return (i);
}
