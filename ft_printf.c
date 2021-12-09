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

void	ft_print_part(const char *str, void *a, int *l)
{
	if (*str == 'c')
		ft_putchar((char)a, l);
	else if (*str == 's')
		ft_putstr((char *)a, l);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr((int)a, l);
	else if (*str == 'u')
		ft_putunbr((unsigned int)a, l);
	else if (*str == 'x')
		ft_putnbr_base((unsigned int)a, "0123456789abcdef", l);
	else if (*str == 'X')
		ft_putnbr_base((unsigned int)a, "0123456789ABCDEF", l);
	else if (*str == 'p')
	{
		ft_putstr("0x", l);
		ft_putnbr_base((unsigned long int)a, "0123456789abcdef", l);
	}
}

char	*ft_flags(const char *str, void *a, int *l)
{	
	if (*str == ' ')
	{
		if ((int)a >= 0 && (*(str + 1) == 'i' || *(str + 1) == 'd'))
			ft_putstr(" ", l);
		else if (*(str + 1) >= '0' && *(str + 1) <= '9')
		{
			while (*str != 's')
				str++;
			ft_putchar(' ', l);
			return ((char *)str);
		}
	}
	else if (*str == '+' && ((int)a >= 0
			&& (*(str + 1) == 'i' || *(str + 1) == 'd')))
		ft_putstr("+", l);
	else
	{
		if (*(str + 1) == 'X' && (int)a != 0)
			ft_putstr("0X", l);
		else if (*(str + 1) == 'x' && (int)a != 0)
			ft_putstr("0x", l);
	}
	str++;
	ft_print_part(str, a, l);
	return ((char *)str);
}

int	ft_printf(const char *str, ...)
{
	va_list	a;
	int		i;

	va_start(a, str);
	i = 0;
	while (*str && str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '#' || *str == ' ' || *str == '+')
				str = ft_flags(str, va_arg(a, void *), &i);
			else if (*str == '%')
				ft_putchar('%', &i);
			else
				ft_print_part(str, va_arg(a, void *), &i);
		}
		else
			ft_putchar(*str, &i);
		str++;
	}
	return (i);
}
