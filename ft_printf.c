/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:15:25 by hfanzaou          #+#    #+#             */
/*   Updated: 2021/11/26 04:44:29 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list a;
	int i;
	char *l;
	va_start(a, str);
	i = 0;
	while (*str && str)
	{
		if (*str == '%')
		{
			str++;
			i++;
			if (*str == 'c')
				ft_putchar_fd((char)va_arg(a, int), 1);
			else if (*str == 's')
				ft_putstr_fd((char *)va_arg(a, char *), 1);
			else if (*str == 'd' || *str == 'i')
				ft_putnbr_fd((int)va_arg(a, int), 1);
			else if (*str == 'u')
				ft_putunbr(va_arg(a, unsigned int));
			else if (*str == 'x')
				ft_putnbr_base(va_arg(a, int), "0123456789abcdef");
			else if (*str == 'X')
				ft_putnbr_base(va_arg(a, int), "0123456789ABCDEF");
			else if (*str == 'p')
				ft_putnbr_base(va_arg(a, int), "0123456789abcdef");
			else if (*str == '%')
				ft_putchar_fd('%', 1);
		}
		else 
			ft_putchar_fd(*str, 1);
		str++;
		i++;
	}
	return (i);
}
