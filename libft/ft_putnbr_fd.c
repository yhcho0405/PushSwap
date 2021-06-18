/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:16:31 by youncho           #+#    #+#             */
/*   Updated: 2020/11/13 12:50:24 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_len_2(long long n)
{
	if (n < 10)
		return (1);
	return (get_len_2(n / 10) + 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int				len;
	long long		tmp;
	char			ret[13];
	int				l;

	len = 0;
	tmp = n;
	if (n < 0)
	{
		len++;
		tmp = -tmp;
	}
	len += get_len_2(tmp);
	l = len;
	ret[len] = 0;
	ret[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		ret[--len] = tmp % 10 + '0';
	if (n < 0)
		ret[0] = '-';
	write(fd, ret, l);
}
