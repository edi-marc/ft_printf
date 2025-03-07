/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:43:27 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/02/20 00:00:15 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
# define PTR_N "(nil)"
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

typedef struct s_fields
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
