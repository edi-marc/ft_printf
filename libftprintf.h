/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:02:15 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/27 15:17:09 by edi-marc         ###   ########.fr       */
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
# define TYPES "cspiduxXnfge%"
# define ZERO 48
# define SPACE 32
# define STAR '*'
# define FLAGS "-0#+\32"
# define PREC '.'

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
char			*get_precision(char *p, t_fields *flds);
char			*get_types(char *p, t_fields *flds);
void			print_conv_c(t_fields *flds, va_list ap);
void			print_conv_ph(t_fields *flds);

#endif
