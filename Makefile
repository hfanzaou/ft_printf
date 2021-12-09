# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 04:35:33 by hfanzaou          #+#    #+#              #
#    Updated: 2021/12/09 12:57:18 by hfanzaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_putnbr.c ft_putstr.c ft_putunbr.c ft_putnbr_base.c ft_printf.c ft_putchar.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJSR = $(SRCS:.c=.o)

BOOJSR = $(SRCS:.c=.o)

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJSR)

%.o: %.c
	$(CC) -c $(CFLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJSR)

bonus : $(BOOJSR)

clean : 
	rm -rf $(OBJSR)

fclean : clean
	rm -rf $(OBJSR) $(NAME)

re : fclean all
