/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:53:14 by hfanzaou          #+#    #+#             */
/*   Updated: 2021/11/26 03:23:19 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "libft/libft.h"
#include <stdarg.h>
int		ft_printf(const char *, ...);
void	ft_putunbr(unsigned int i);
void	ft_putnbr_base(int nbr, char *base);
#endif