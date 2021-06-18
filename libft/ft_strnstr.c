/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:48:55 by youncho           #+#    #+#             */
/*   Updated: 2020/11/13 12:42:19 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	idx;
	size_t	nlen;
	size_t	hlen;

	if (!*n)
		return ((char *)h);
	if (!len || !(hlen = ft_strlen(h)) ||
		len < (nlen = ft_strlen(n)))
		return (0);
	idx = 0;
	while (idx + nlen <= len && idx + nlen <= hlen)
	{
		if (!ft_strncmp((char *)(h + idx), (char *)n, nlen))
			return ((char *)(h + idx));
		idx++;
	}
	return (0);
}
