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
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putunbr(unsigned int i, int *l);
void	ft_putnbr_base(unsigned long int nbr, char *base, int *l);
void	ft_putstr(char *str, int *l);
void	ft_putnbr(int n, int *l);
void	ft_putchar(char c, int *l);

#endif
