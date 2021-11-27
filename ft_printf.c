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

int ft_printf(const char *str, ...)
{
	va_list a;
	static int i;

	va_start(a, str);
	i = 0;
	while (*str && str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				ft_putchar_fd((char)va_arg(a, int), 1);
				i++;
			}
			else if (*str == 's')
				ft_putstr(va_arg(a, char *), &i);
			else if (*str == 'd' || *str == 'i')
				ft_putnbr(va_arg(a, int), &i);
			else if (*str == 'u')
				ft_putunbr(va_arg(a, unsigned int), &i);
			else if (*str == 'x')
				ft_putnbr_base(va_arg(a, unsigned int), "0123456789abcdef", &i);
			else if (*str == 'X')
				ft_putnbr_base(va_arg(a, unsigned int), "0123456789ABCDEF", &i);
			else if (*str == 'p')
			{
				ft_putstr_fd("0x", 1);
				i += 2;
				ft_putnbr_base(va_arg(a, unsigned long int), "0123456789abcdef", &i);
			}
			else if (*str == '%')
			{
				i++;
				ft_putchar_fd('%', 1);
			}
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
