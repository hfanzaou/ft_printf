# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 04:35:33 by hfanzaou          #+#    #+#              #
#    Updated: 2021/11/27 04:58:46 by hfanzaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_putnbr.c ft_putstr.c ft_putunbr.c ft_putnbr_base.c ft_printf.c 

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJSR = $(SRCS:.c=.o)

NAME = libftprintf.a

LIBNAME = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJSR) $(LIBNAME)

$(LIBNAME) : 
	make ./libft

$(OBJSR) : $(SRCS)
	$(CC) $(CFLAGS) -c $<
	ar rcs $(NAME) $(OBJSR) $(LIBNAME)

clean :
	make clean ./libft
	rm -rf $(OBJS)

fclean : clean
	make fclean ./libft
	rm -rf $(OBJS) $(NAME)

re : fclean all
