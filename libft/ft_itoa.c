/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:15:31 by youncho           #+#    #+#             */
/*   Updated: 2020/11/03 12:56:23 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_len(long long n)
{
	if (n < 10)
		return (1);
	return (get_len(n / 10) + 1);
}

char	*ft_itoa(int n)
{
	char			*ret;
	int				len;
	long long		tmp;

	len = 0;
	tmp = n;
	if (n < 0)
	{
		len++;
		tmp = -tmp;
	}
	len += get_len(tmp);
	if (!(ret = malloc(len + 1)))
		return (0);
	ret[len] = 0;
	ret[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		ret[--len] = tmp % 10 + '0';
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
