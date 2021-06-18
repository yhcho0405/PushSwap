/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:40:14 by youncho           #+#    #+#             */
/*   Updated: 2020/11/13 14:28:26 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LLONG_MAX 9223372036854775807

int	check_llong(unsigned long long ans, int sign)
{
	if (sign == -1 && LLONG_MAX <= ans)
		return (0);
	if (sign == 1 && LLONG_MAX < ans)
		return (-1);
	return (sign * ans);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	ans;

	ans = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		ans *= 10;
		ans += *str - '0';
		str++;
	}
	return (check_llong(ans, sign));
}
