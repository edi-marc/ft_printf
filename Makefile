# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 14:30:20 by emdi-mar          #+#    #+#              #
#    Updated: 2025/02/19 23:42:59 by emdi-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_printf_conv_spec_utils.c \
	ft_printf_print_conv_utils_c_ph.c ft_printf_print_conv_utils_sid.c\
	ft_printf_print_conv_utils_u.c ft_printf_print_conv_utils_x.c \
	ft_printf_print_conv_utils_p.c

OBJS = $(SRCS:.c=.o)

HEADERS = ft_printf.h

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

LIB = ar rcs

CC = cc
	
RM = /bin/rm -f

CP = /bin/cp

CFLAGS = -Wall -Wextra -Werror	

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIBFT): $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR) 

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	 $(LIB) $(LIBFT) $(OBJS)
	 $(CP) $(LIBFT) $(NAME)

clean: $(LIBFT_DIR)
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

bonus: re

.PHONY: all clean fclean re bonus
