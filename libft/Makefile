# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 22:59:42 by emdi-mar          #+#    #+#              #
#    Updated: 2025/02/19 17:04:14 by emdi-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_atoi.c \
	ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c ft_iultoa_base_bonus.c ft_iutoa_base_bonus.c ft_iutoa_bonus.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

HEADERS = libft.h

LIB = ar rc

PLIB = ranlib

LIB2 = ar rcs

CC = cc

GCC = gcc
	
RM = /bin/rm -f

CFLAGS = -Wall -Wextra -Werror	

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):$(OBJS) $(HEADERS)
	$(LIB2) $(NAME) $(OBJS)	

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

bonus: $(OBJS) $(BOBJS) $(HEADERS)
	$(LIB2) $(NAME) $(OBJS) $(BOBJS)

re: fclean all

bre: fclean bonus

.PHONY: all clean fclean bonus re bre
