/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:33:18 by youncho           #+#    #+#             */
/*   Updated: 2020/10/31 13:53:18 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *ret;

	if (!(ret = (char *)malloc(ft_strlen(s1) + 1)))
		return (0);
	ft_memcpy(ret, s1, ft_strlen(s1) + 1);
	return (ret);
}
