/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 03:21:46 by hfanzaou          #+#    #+#             */
/*   Updated: 2021/11/26 03:26:59 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	check(int a, char *c)
{
	int	i;
	int	j;

	i = 0;
	if (a < 2)
		return (0);
	while (c[i] != '\0')
	{
		j = i + 1;
		while (c[j])
		{
			if (c[i] == c[j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '+' || c[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	unsigned int	nbr2;

	i = 0;
	while (base[i] != '\0')
		i++;
	if (check(i, base) == 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = nbr * (-1);
		}
		nbr2 = nbr;
		if (nbr2 >= i)
		{
			ft_putnbr_base(nbr2 / i, base);
		}
		ft_putchar_fd(base[nbr2 % i], 1);
	}
}
