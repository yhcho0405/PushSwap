/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:02:11 by youncho           #+#    #+#             */
/*   Updated: 2021/02/11 01:34:51 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	placeholder_init(t_placeholder *state)
{
	state->align = FALSE;
	state->fill = FALSE;
	state->width = FALSE;
	state->precision = UNUSED;
}

int		print_placeholder(char specifier, va_list ap, t_placeholder *state)
{
	if (specifier == 'c')
		return (print_c(state, va_arg(ap, int)));
	else if (specifier == 's')
		return (print_s(state, va_arg(ap, char*)));
	else if (specifier == 'p')
		return (print_p(state, (unsigned long long)va_arg(ap, void*)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_di(state, va_arg(ap, int)));
	else if (specifier == 'u')
		return (print_ux(state, va_arg(ap, unsigned int), BASE10));
	else if (specifier == 'x')
		return (print_ux(state, va_arg(ap, unsigned int), BASE16L));
	else if (specifier == 'X')
		return (print_ux(state, va_arg(ap, unsigned int), BASE16U));
	else if (specifier == '%')
		return (print_c(state, '%'));
	return (0);
}

void	parse_placeholder(const char **format, va_list ap, int *len)
{
	t_placeholder	state;

	(*format)++;
	placeholder_init(&state);
	while (**format && !find_char(**format, SPECIFIER))
	{
		while (**format && !find_char(**format, NONPASS))
			(*format)++;
		parse_flag(format, &state);
		parse_width(format, &state, ap);
		parse_precision(format, &state, ap);
	}
	if (**format)
		*len += print_placeholder(*(*format)++, ap, &state);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
		if (*format == '%')
			parse_placeholder(&format, ap, &len);
		else
		{
			ft_putchar_fd(*format++, 1);
			len++;
		}
	va_end(ap);
	return (len);
}
