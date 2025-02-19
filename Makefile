# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 14:30:20 by emdi-mar          #+#    #+#              #
#    Updated: 2025/02/19 14:30:33 by emdi-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
	   ft_memmove.c ft_memchr.c ft_strlen.c ft_strchr.c \
	   ft_strrchr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	   ft_isascii.c ft_isprint.c ft_toupper.c ft_strncmp.c \
	   ft_tolower.c ft_strlcpy.c ft_strlcat.c ft_memcmp.c ft_atoi.c \
	   ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	   ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_iutoa_bonus.c ft_iutoa_base_bonus.c ft_iultoa_base_bonus.c \

L_SRCS = $(addprefix libft/, $(SRCS))

PF_SRCS = ft_printf.c ft_printf_utils.c ft_printf_conv_spec_utils.c \
		  ft_printf_print_conv_utils_csid_ph.c ft_printf_print_conv_utils_ux.c \
		  ft_printf_print_conv_utils_p.c \

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c \

L_BSRCS = $(addprefix libft/, $(BSRCS))

OBJS = $(L_SRCS:.c=.o) $(PF_SRCS:.c=.o)

BOBJS = $(L_BSRCS:.c=.o)

INCLUDE = libft

LIB = ar rcs

CC = cc
	
RM = /bin/rm -f

CFLAGS = -Wall -Wextra -Werror	

all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(INCLUDE)
	@$(LIB) $(NAME) $(OBJS)
	@make clean	

clean:
	@$(RM) $(OBJS) $(BOBJS)

fclean: clean
	@$(RM) $(NAME)

bonus: $(OBJS) $(BOBJS) $(INCLUDE)
	@$(LIB) $(NAME) $(OBJS) $(BOBJS)
	@make clean

re: fclean all

bre: fclean bonus

.PHONY: all clean fclean re bonus bre
