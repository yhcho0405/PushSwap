/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:14:13 by youncho           #+#    #+#             */
/*   Updated: 2020/11/13 14:42:43 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	sl;

	if (!s)
		return (0);
	sl = ft_strlen(s);
	if (start >= sl)
		start = sl;
	else
		len = start + len > sl ? sl - start : len;
	if (!(ret = (char *)malloc(len + 1)))
		return (0);
	ft_memcpy(ret, s + start, len);
	ret[len] = 0;
	return (ret);
}
