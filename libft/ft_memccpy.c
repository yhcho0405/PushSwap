/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:56:28 by youncho           #+#    #+#             */
/*   Updated: 2020/11/16 19:07:47 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*((char *)dst++) = *((char *)src);
		if (*((unsigned char *)src++) == (unsigned char)c)
			return (dst);
	}
	return (0);
}
