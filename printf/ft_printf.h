/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:02:15 by youncho           #+#    #+#             */
/*   Updated: 2021/06/20 07:09:14 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# define NONPASS "-0.*123456789cspdiuxX%"
# define FLAG "-0"
# define SPECIFIER "cspdiuxX%"
# define BASE10 "0123456789"
# define BASE16L "0123456789abcdef"
# define BASE16U "0123456789ABCDEF"

# define R_ERR -1
# define TRUE 1
# define FALSE 0
# define UNUSED -1

typedef struct	s_placeholder
{
	int			align;
	int			fill;
	int			width;
	int			precision;
}				t_placeholder;

void			placeholder_init(t_placeholder *state);
int				print_placeholder(char specifier, va_list ap,
									t_placeholder *state);
void			parse_placeholder(const char **format, va_list ap, int *len);
int				ft_printf(const char *format, ...);

int				find_char(char c, const char *set);
void			parse_flag(const char **format, t_placeholder *state);
void			parse_width(const char **format, t_placeholder *state,
							va_list ap);
void			parse_precision(const char **format, t_placeholder *state,
								va_list ap);
char			*get_base_str(unsigned long long num, const char *base,
								int precision);

int				print_c(t_placeholder *state, char c);
int				print_s(t_placeholder *state, char *str);
int				print_p(t_placeholder *state, unsigned long long ptr);
int				print_ux(t_placeholder *state, unsigned long long num,
						char *base);
int				print_di(t_placeholder *state, long long num);

#endif
