# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/21 18:53:18 by edi-marc          #+#    #+#              #
#    Updated: 2021/02/21 19:31:35 by edi-marc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NAME_LFT = libft/libft.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

INCLUDE = ft_printf.h

LIB = ar rcs

CC = gcc

RM = /bin/rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(INCLUDE)
	cd libft && $(MAKE)
	$(LIB) $(NAME) $(NAME_LFT) $(OBJS)
