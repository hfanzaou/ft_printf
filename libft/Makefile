# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 02:06:30 by hfanzaou          #+#    #+#              #
#    Updated: 2021/11/22 03:50:27 by hfanzaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		ft_tolower.c ft_toupper.c

OBJSRCS = $(SRCS:.c=.o)

BSRCS = ft_lstnew_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
		ft_lstlast_bonus.c

BOSRCS = $(BSRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJSRCS)

%.o: %.c
	$(CC) -c $< -o $@
	ar rcs $(NAME) $@

bonus: $(BOSRCS) $(OBJSRCS)

clean:
	rm -rf $(OBJSRCS) $(BOSRCS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
