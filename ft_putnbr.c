/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:14:31 by hfanzaou          #+#    #+#             */
/*   Updated: 2021/11/27 01:14:34 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void    ft_putnbr(int n, int *l)
{
    unsigned int	i;

	i = n;
	if (n < 0)
	{
		i = -n;
		*l += 1;
		ft_putchar_fd('-', 1);
	}
	if (i > 9)
	{
		ft_putnbr(i / 10, l);
	}
    *l += 1;
	ft_putchar_fd(i % 10 + 48, 1);
}