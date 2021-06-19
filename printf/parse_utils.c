/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:10:17 by youncho           #+#    #+#             */
/*   Updated: 2021/02/11 01:31:02 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_char(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (TRUE);
		set++;
	}
	return (FALSE);
}

void	parse_flag(const char **format, t_placeholder *state)
{
	if (**format == '-')
		state->align = TRUE;
	else if (**format == '0')
		state->fill = TRUE;
	else
		return ;
	(*format)++;
}

void	parse_width(const char **format, t_placeholder *state, va_list ap)
{
	if (**format == '*')
	{
		state->width = va_arg(ap, int);
		if (state->width < 0)
		{
			state->align = 1;
			state->width *= -1;
		}
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		state->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void	parse_precision(const char **format, t_placeholder *state, va_list ap)
{
	if (**format != '.')
		return ;
	(*format)++;
	state->precision = 0;
	if (**format == '*')
	{
		state->precision = va_arg(ap, int);
		if (state->precision < 0)
			state->precision = -1;
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		state->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

char	*get_base_str(unsigned long long num, const char *base, int precision)
{
	int						len;
	char					*ret;
	int						base_len;
	unsigned long long		tnum;

	tnum = num;
	base_len = ft_strlen(base);
	len = 0;
	while (tnum /= base_len)
		len++;
	len++;
	if (!num && !precision)
		len = 0;
	ret = malloc(len + 1);
	ret[len] = 0;
	while (--len >= 0)
	{
		ret[len] = base[(num % base_len)];
		num /= base_len;
	}
	return (ret);
}
