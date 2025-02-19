/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:02:15 by edi-marc          #+#    #+#             */
/*   Updated: 2021/03/04 15:37:19 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define STDO 1
# define ERR -1

/*
**	If PH is modified remember to modify the corresponding
**	value on TYPES
*/
# define PH '%'
# define TYPES "cspiduxX%"
# define ZERO 48
# define SPACE 32
# define MINUS '-'
# define STR_N "(null)"
# define STAR '*'
# define FLAGS "-0#+\32"
# define PREC '.'

/*
**	LEN_PX is the lenght of the prefix
**	used by 'x' / 'X' / 'p' conversions
*/
# define LEN_PX 2
# define HEX "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"

typedef struct	s_fields
{
	int		printed;
	int		minus;
	int		plus;
	int		zero;
	int		space;
	int		hash;
	int		width;
	int		dot;
	char	type;
}				t_fields;

int				ft_printf(const char *fmt, ...);
void			init_fields(t_fields *flds);
void			reset_fields(t_fields *flds);
void			putchar_ftprintf(char c, t_fields *flds);
void			get_flag(char c, t_fields *flds);
char			*get_width(char *p, t_fields *flds, va_list ap);
char			*get_precision(char *p, t_fields *flds, va_list ap);
char			*get_types(char *p, t_fields *flds);
void			print_conv_c(t_fields *flds, va_list ap);
void			print_conv_s(t_fields *flds, va_list ap);
void			print_conv_i(t_fields *flds, va_list ap);
void			print_conv_ph(t_fields *flds);
void			print_conv_u(t_fields *flds, va_list ap);
void			print_conv_x(t_fields *flds, va_list ap, char *base);
void			print_conv_p(t_fields *flds, va_list ap, char *base);

#endif
